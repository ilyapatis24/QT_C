#ifndef SPINNER_H
#define SPINNER_H

#include <QPointer>
#include <QWidget>

namespace SpinnerSolution {

enum class SpinnerSize { Small, Medium, Large };

enum class SpinnerState { NotRunning, Running };

// TODO: SpinnerOverlay and SpinnerWidget?

class SpinnerOverlay;

class Spinner : public QObject
{
    Q_OBJECT

public:
    explicit Spinner(SpinnerSize size, QWidget *parent = nullptr);
    ~Spinner() override;
    void setSize(SpinnerSize size);
    void setColor(const QColor &color);
    void show();
    void hide();
    bool isVisible() const;
    void setVisible(bool visible);

private:
    QPointer<SpinnerOverlay> m_widget;
};

class SpinnerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpinnerWidget(QWidget *parent = nullptr);
    void setState(SpinnerState state);
    void setDecorated(bool on);

private:
    class SpinnerWidgetPrivate *d;
};

} // namespace SpinnerSolution

#endif // SPINNER_H
