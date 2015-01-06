#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "neuron.h"
#include <QImage>

struct Pattern
{
    Pattern(const QImage& image, int type);
    //
    QImage img;
    int type;
};


class Perceptron
{
public:
    // in - кол-во сенсоров, out - кол-во выходов
    Perceptron(int in, int out);
    ~Perceptron();
    // обучение сети набором trSet
    void train(const QList<Pattern> trSet);    
    // классификация сетью изображения
    int classify(const QImage& image);
    //
private:
    // слой сенсоров
    QList<Sensor> sensors;
    // промежуточный слой
    QList<Associative*> associatives;
    // результирующий слой
    QList<Resulting> resultings;
    // предъявление сети изображения
    void recognize(const QImage& image);
    // пересчёт весов A-R
    void overestimateAR(int rIdx, int value);
    // вычисление реакции нейронов A слоя
    void calcReactionA();
};

#endif // PERCEPTRON_H
