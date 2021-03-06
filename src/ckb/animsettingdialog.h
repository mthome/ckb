#ifndef ANIMSETTINGDIALOG_H
#define ANIMSETTINGDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QFrame>
#include <QSignalMapper>
#include <QSpinBox>
#include "kbanim.h"

namespace Ui {
class AnimSettingDialog;
}

class AnimSettingDialog : public QDialog
{
    Q_OBJECT

public:
    // Create with the dialog parent, and the animation to edit. Use exec() to present.
    explicit AnimSettingDialog(QWidget* parent, KbAnim* anim);
    ~AnimSettingDialog();

    // Applies settings to the animation
    void applySettings();
    // Gets the name entered
    QString name() const;

private:
    Ui::AnimSettingDialog *ui;
    QCheckBox* stopCheck, *kpStopCheck;
    bool hasRepeat;

    KbAnim* _anim;
    double lastDuration;
    QMap<QString, QWidget*> settingWidgets;
    QMap<QString, QSpinBox*> angleSpinners;
    QSignalMapper angleDialMapper, angleSpinnerMapper;

    QFrame* hLine();

private slots:
    void newDuration(double duration);
    void updateStops();
    void angleDialChanged(QString name);
    void angleSpinnerChanged(QString name);
};

#endif // ANIMSETTINGDIALOG_H
