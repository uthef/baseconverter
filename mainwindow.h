#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow : public QObject{
    Q_OBJECT

    Q_PROPERTY(QString binStr READ binStr NOTIFY binStrUpdated)
    Q_PROPERTY(QString octStr READ octStr NOTIFY octStrUpdated)
    Q_PROPERTY(QString decStr READ decStr NOTIFY decStrUpdated)
    Q_PROPERTY(QString hexStr READ hexStr NOTIFY hexStrUpdated)
    Q_PROPERTY(QString fieldText READ fieldText WRITE setFieldText NOTIFY onFieldTextUpdated)

public:
    explicit MainWindow(QObject *parent = nullptr);
    QString binStr() const;
    QString octStr() const;
    QString decStr() const;
    QString hexStr() const;
    QString fieldText() const;
    void setFieldText(QString value);
signals:
    void binStrUpdated();
    void octStrUpdated();
    void decStrUpdated();
    void hexStrUpdated();
    void onFieldTextUpdated();
public slots:
    void onFieldInput(QString text);
    void onComboIndexChanged(unsigned int value);
private:
    unsigned int _currentBase;

    QString _binStr = "0000";
    QString _octStr = "0";
    QString _decStr = "0";
    QString _hexStr = "0";
    QString _fieldText;

    void updateStr(QString hexStr, QString decStr, QString octStr, QString binStr);
};

#endif // MAINWINDOW_H
