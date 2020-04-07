// main.cpp
#include <QApplication>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTreeView>
//https://www.qtcentre.org/threads/49656-ContextMenu-in-QTreeView
//https://www.qtcentre.org/threads/19919-Custom-context-menu-in-QTreeView

class QPropertyEditorWidget : public QTreeView
{
	Q_OBJECT
public:

	
	QPropertyEditorWidget(QWidget* parent = 0);

	/// Destructor
	virtual ~QPropertyEditorWidget();

	
public slots:

	void displayPairingMenu(const QPoint &pos)
	{

	}

	
};

QPropertyEditorWidget::QPropertyEditorWidget(QWidget* parent /*= 0*/) : QTreeView(parent)
{
	connect(this, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(displayPairingMenu(QPoint)));
}


QPropertyEditorWidget::~QPropertyEditorWidget()
{
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QStandardItemModel model;


	for (int i = 0; i < 10; ++i) {
		const QString rowText = QLatin1String("Row ") + QString::number(i);
		QStandardItem *child = new QStandardItem(rowText);
		for (int j = 0; j < 1; ++j) {
			child->appendRow(new QStandardItem(rowText + QLatin1Char('/') + QString::number(j)));
		}
		model.appendRow(child);
	}

	QPropertyEditorWidget treeView;
	//connect(treeView, &QWidget::customContextMenuRequested,this, &MainWindow::onCustomContextMenuRequested);
	//QObject::connect(treeView, SIGNAL(customContextMenuRequested(QPoint)), treeView, SLOT(displayPairingMenu(QPoint)));
	treeView.setContextMenuPolicy(Qt::ActionsContextMenu);
	treeView.setModel(&model);
	

	/*
		QAction *foo = new QAction("Foo", 0);
	foo->setShortcut(QKeySequence("Ctrl+F"));
	QMenu *menu = new QMenu();
	menu->addAction(foo);
	*/
	treeView.show();
	return app.exec();
}

#include "main.moc"