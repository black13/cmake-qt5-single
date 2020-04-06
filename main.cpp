// main.cpp
#include <QApplication>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTreeView>

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

	QTreeView treeView;
	treeView.setModel(&model);

  

	treeView.show();
	return app.exec();
}

#include "main.moc"