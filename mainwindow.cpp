#include "mainwindow.h"

#include "baseconverter.h"
#include "qdebug.h"

#define BC BaseConverter

MainWindow::MainWindow(QObject *parent) : QObject{parent} {
    updateStr("0", "0", "0", "0000");
}

void MainWindow::updateStr(QString hexStr, QString decStr, QString octStr, QString binStr) {
    _binStr = binStr;
    _octStr = octStr;
    _decStr = decStr;
    _hexStr = hexStr;

    emit binStrUpdated();
    emit octStrUpdated();
    emit decStrUpdated();
    emit hexStrUpdated();
}

QString MainWindow::binStr() const {
    return _binStr;
}

QString MainWindow::octStr() const {
    return _octStr;
}

QString MainWindow::decStr() const {
    return _decStr;
}

QString MainWindow::hexStr() const {
    return _hexStr;
}

QString MainWindow::fieldText() const {
    return _fieldText;
}

void MainWindow::setFieldText(QString value) {
    _fieldText = value;
    emit onFieldTextUpdated();
}

void MainWindow::onFieldInput(QString text) {
    _fieldText = text;

    try {
        auto decStr = BC::transform(text.toStdString(), (BC::Base)_currentBase, BC::DEC);

        updateStr(
            QString::fromStdString(BC::transform(decStr, BC::DEC, BC::HEX)),
            QString::fromStdString(decStr),
            QString::fromStdString(BC::transform(decStr, BC::DEC, BC::OCT)),
            QString::fromStdString(BC::transform(decStr, BC::DEC, BC::BIN))
        );
    }
    catch (std::invalid_argument&) {
        updateStr("0", "0", "0", "0000");
    }
    catch (std::out_of_range&) {
        updateStr("0", "0", "0", "0000");
    }
}

void MainWindow::onComboIndexChanged(unsigned int value) {
    QString newFieldText = "0";

    try {
        auto conv =
            BC::transform(
                _fieldText.toStdString(),
                (BC::Base)_currentBase,
                (BC::Base)value
            );

            newFieldText = QString::fromStdString(conv);
    }
    catch (std::invalid_argument&) {
        newFieldText = "0";
        updateStr("0", "0", "0", "0000");
    }
    catch (std::out_of_range) {
        newFieldText = "0";
        updateStr("0", "0", "0", "0000");
    }

    _currentBase = value;
    setFieldText(newFieldText);
}
