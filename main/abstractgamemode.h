#pragma once
#include <QtCore/QObject>

class QPainter;
class QRect;

class AbstractGameMode : public QObject {
	Q_OBJECT
public:
	enum {
		CONTROL_NONE, CONTROL_SKIP, CONTROL_LEFT, CONTROL_RIGHT, CONTROL_UP,
		CONTROL_DOWN, CONTROL_UNDO, CONTROL_HOME, CONTROL_QUIT, CONTROL_OPEN,
		CONTROL_CHEAT_RESTART, CONTROL_CHEAT_SKIP_LEVEL
	} Control;

	AbstractGameMode(QObject * parent = 0) : QObject(parent) {}
	virtual ~AbstractGameMode() {}

	virtual void invalidateRect() = 0;
	virtual void paint(QPainter * painter, const QRect & rect) = 0;
	virtual void processControl(int control) = 0;
};
