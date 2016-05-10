#ifndef STRIP_H
#define STRIP_H

#include <QWidget>

namespace Ui {
class Strip;
}

class Strip : public QWidget
{
    Q_OBJECT

public:
    explicit Strip(QWidget *parent = 0);
    ~Strip();

private:
    Ui::Strip *ui;
};

#endif // STRIP_H
