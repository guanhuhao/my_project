import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
# number 1 to 10 data
mnist = input_data.read_data_sets('MNIST_data', one_hot=True)


# tem
def tf_confusion_metrics(model, actual_classes, session, feed_dict):
    predictions = tf.argmax(model, 1)
    actuals = tf.argmax(actual_classes, 1)

    ones_like_actuals = tf.ones_like(actuals)
    zeros_like_actuals = tf.zeros_like(actuals)
    ones_like_predictions = tf.ones_like(predictions)
    zeros_like_predictions = tf.zeros_like(predictions)

    tp_op = tf.reduce_sum(
      tf.cast(
        tf.logical_and(
          tf.equal(actuals, ones_like_actuals),
          tf.equal(predictions, ones_like_predictions)
        ),
        "float"
      )
    )

    tn_op = tf.reduce_sum(
      tf.cast(
        tf.logical_and(
          tf.equal(actuals, zeros_like_actuals),
          tf.equal(predictions, zeros_like_predictions)
        ),
        "float"
      )
    )

    fp_op = tf.reduce_sum(
      tf.cast(
        tf.logical_and(
          tf.equal(actuals, zeros_like_actuals),
          tf.equal(predictions, ones_like_predictions)
        ),
        "float"
      )
    )

    fn_op = tf.reduce_sum(
      tf.cast(
        tf.logical_and(
          tf.equal(actuals, ones_like_actuals),
          tf.equal(predictions, zeros_like_predictions)
        ),
        "float"
      )
    )
    tp, tn, fp, fn = \
        session.run(
            [tp_op, tn_op, fp_op, fn_op],
            feed_dict
        )
    if float(tp) + float(fn) == 0:
        tpr = 0
        fpr = 0
        accuracy1 = 0
        f1_score1 = 0
    else:
        tpr = float(tp) / (float(tp) + float(fn))
        fpr = float(fp) / (float(tp) + float(fn))
        accuracy1 = (float(tp) + float(tn)) / (float(tp) + float(fp) + float(fn) + float(tn))
        f1_score1 = (2 * float(tp)) / (2 * float(tp) + float(fp) + float(fn))

    recall1 = tpr
    # precision1 = float(tp) / (float(tp) + float(fp))

    #  print('Precision = ', precision1)
    print('Recall = ', recall1)
    print('F1 Score = ', f1_score1)
    print('Accuracy = ', accuracy1)


# tem


def compute_accuracy(v_xs, v_ys):
    global prediction
    y_pre = sess.run(prediction, feed_dict={xs: v_xs, keep_prob: 1})
    correct_prediction = tf.equal(tf.argmax(y_pre, 1), tf.argmax(v_ys, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
    result = sess.run(accuracy, feed_dict={xs: v_xs, ys: v_ys, keep_prob: 1})
    print('text:%d   prediction:%f' % (i, result))
    tf_confusion_metrics(y_pre, v_ys, sess, feed_dict={xs: v_xs, ys: v_ys, keep_prob: 1})
    return result



def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)


def bias_variable(shape):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial)


def conv2d(x, W):
    return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME')


def max_pool_2x2(x):
    return tf.nn.max_pool(x, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')


# define placeholder for inputs to network
with tf.name_scope('input'):
    xs = tf.placeholder(tf.float32, [None, 784])
    ys = tf.placeholder(tf.float32, [None, 10])
keep_prob = tf.placeholder(tf.float32)
x_image = tf.reshape(xs, [-1, 28, 28, 1])


# conv1 layer
n_layer = 1
layer_name = 'layer%s' % n_layer
with tf.name_scope(layer_name):
    with tf.name_scope('Weight'):
        W_conv1 = weight_variable([5, 5, 1, 32])
        tf.summary.histogram(layer_name + '/weight', W_conv1)
    with tf.name_scope('biases'):
        b_conv1 = bias_variable([32])
        tf.summary.histogram(layer_name + 'variable', b_conv1)
    with tf.name_scope('output'):
        h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1)
        tf.summary.histogram(layer_name + 'output', h_conv1)
    h_pool1 = max_pool_2x2(h_conv1)

# conv2 layer
n_layer = 2
layer_name = 'layer%s' % n_layer
with tf.name_scope(layer_name):
    with tf.name_scope('Weight'):
        W_conv2 = weight_variable([5, 5, 32, 64])
        tf.summary.histogram(layer_name + '/weight', W_conv2)
    with tf.name_scope('biases'):
        b_conv2 = bias_variable([64])
        tf.summary.histogram(layer_name + 'variable', b_conv2)
    with tf.name_scope('output'):
        h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2) + b_conv2)
        tf.summary.histogram(layer_name + 'output', h_conv2)
        h_pool2 = max_pool_2x2(h_conv2)

# func1 layer
W_fc1 = weight_variable([7*7*64, 1024])
b_fc1 = bias_variable([1024])

h_pool2_flat = tf.reshape(h_pool2, [-1, 7*7*64])
h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1)+b_fc1)
h_fc1_drop = tf.nn.dropout(h_fc1, keep_prob)
# func2 layer
W_fc2 = weight_variable([1024, 10])
b_fc2 = bias_variable([10])
prediction = tf.nn.softmax(tf.matmul(h_fc1_drop, W_fc2)+b_fc2)



# the loss between prediction and real data
with tf.name_scope('cross_entropy'):
    cross_entropy = tf.reduce_mean(-tf.reduce_sum(ys*tf.log(prediction), reduction_indices=[1]))
    tf.summary.scalar('cross_entropy', cross_entropy)

train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)

sess = tf.Session()

# important step
sess.run(tf.global_variables_initializer())

# show graph
merged = tf.summary.merge_all()
writer = tf.summary.FileWriter('logs', sess.graph)


for i in range(5000):
    batch_xs, batch_ys = mnist.train.next_batch(100)
    sess.run(train_step, feed_dict={xs: batch_xs, ys: batch_ys, keep_prob: 0.5})
    if i % 50 == 0:
        result = sess.run(merged, feed_dict={xs: batch_xs, ys: batch_ys, keep_prob: 1})
        writer.add_summary(result, i)
        compute_accuracy(mnist.test.images, mnist.test.labels)


