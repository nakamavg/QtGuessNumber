# QtGuessNumber

## My first app in Qt

- Qt is a cross-platform framework for developing graphical user interfaces (GUIs) and applications.
- It provides a comprehensive set of tools and libraries for building interactive and visually appealing software.
- Qt allows developers to write code once and deploy it on multiple platforms, including Windows, macOS, Linux, Android, and iOS.
- With Qt, you can create desktop applications, mobile apps, embedded systems, and even applications for the Internet of Things (IoT).
- It supports various programming languages, including C++, Python, and JavaScript, making it accessible to a wide range of developers.

- Main

```cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Widget w;
	w.show();
	return a.exec();
}
```
### class widget

```c++
	#ifndef WIDGET_H
	#define WIDGET_H

	#include <QWidget>

	QT_BEGIN_NAMESPACE
	namespace Ui {
	class Widget;
	}
	QT_END_NAMESPACE

	class Widget : public QWidget
	{
		Q_OBJECT

	public:
		Widget(QWidget *parent = nullptr);
		~Widget();

	private slots:
		void on_guessButton_clicked();

		void on_startOverButton_clicked();

	private:
		Ui::Widget *ui;
		int secret_number;
		int guess_number;
	};
	#endif // WIDGET_H
```

