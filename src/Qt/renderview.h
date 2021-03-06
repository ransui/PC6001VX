#ifndef RENDERVIEW_H
#define RENDERVIEW_H

#include <QGraphicsView>

class RenderView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit RenderView(QGraphicsScene *scene, QWidget *parent = 0);
	~RenderView();

signals:
	void resized(QSize);

public slots:
	// シーングラフ全体がウィジェットに収まるように表示倍率を調整
	// fitInViewだと微妙に倍率が合わないので独自実装
	void fitContent();

	// 指定した倍率(%)で表示されるようにウィンドウをリサイズ
	void resizeWindowByRatio(int ratio);

protected:
	// QWidget interface
	virtual bool event(QEvent *) override;
	virtual void paintEvent(QPaintEvent* event) override;
	virtual void contextMenuEvent(QContextMenuEvent *event) override;
	virtual void wheelEvent(QWheelEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // RENDERVIEW_H
