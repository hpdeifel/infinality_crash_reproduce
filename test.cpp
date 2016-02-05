#include <poppler-qt4.h>
#include <QString>
#include <QImage>

int main(int, char **argv)
{
	QString filename(argv[1]);
	Poppler::Document* document = Poppler::Document::load(filename);

	document->setRenderHint(Poppler::Document::TextHinting, true);
	document->setRenderHint(Poppler::Document::TextSlightHinting, true);

	Poppler::Page* pdfPage = document->page(0);

	// dpi must be high enough
	QImage image = pdfPage->renderToImage(200, 200);

	return 0;
}
