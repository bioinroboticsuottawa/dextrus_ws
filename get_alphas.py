import os
import yaml
import tensorflow as tf
import numpy as np

file = os.getcwd() + '/file.yaml'
file = open(file)

node = yaml.load(file)

x = range(21)
y = range(21)

for k, v in node.items():
    mean = {'D': 0.0, 'M': 0.0, 'P': 0.0}

    factor = 1.0/float(len(v))

    for i in v:
        mean['D'] += i['G_MiddleDIJ'] * factor
        mean['M'] += i['G_MiddleMPJ'] * factor
        mean['P'] += i['G_MiddlePIJ'] * factor

    x[k/5] = [mean['P'], mean['M'], mean['D']]
    y[k/5] = float(k)

print x
print y

x_data = tf.Variable(tf.transpose(x))
y_data = tf.Variable(y)
W = tf.Variable(tf.random_uniform([3, 1], 0.0, 2.0))
b = tf.Variable(tf.zeros([1]))

y_formula = x_data * W #+ b

loss = tf.reduce_mean(tf.square(y_formula - y_data))
train = tf.train.GradientDescentOptimizer(0.001).minimize(loss)

init = tf.initialize_all_variables()

W_result = []
b_result = []

with tf.Session() as sess:
    sess.run(init)

    print sess.run(x_data)
    print sess.run(y_formula)

    for step in xrange(1000):
        sess.run(train)

        if step % 20 == 0:
            print "W: ", sess.run(W)
            #print "b: ", sess.run(b)

    W_result = sess.run(tf.transpose(W))
    #b_result = sess.run(tf.transpose(b))

print "W final: ", W_result
#print "b final: ", b_result

#calculo do erro medio
erro_medio = 0;
for i in xrange(len(x)):
    y_ = np.dot(x[i], W_result[0]) #+ b_result[0]
    erro_quad = np.abs(y_ - y[i])**2
    erro_medio += erro_quad
    print "Erro:", erro_quad

erro_medio = (erro_medio/len(x))**0.5
print "Erro medio:", erro_medio
