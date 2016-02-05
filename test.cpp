#include <poppler-qt4.h>
#include <QString>
#include <QImage>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " PDF" << std::endl;
		return 1;
	}

	QString filename(argv[1]);
	Poppler::Document* document = Poppler::Document::load(filename);

	document->setRenderHint(Poppler::Document::TextHinting, true);
	document->setRenderHint(Poppler::Document::TextSlightHinting, true);

	Poppler::Page* pdfPage = document->page(0);

	// dpi must be high enough
	QImage image = pdfPage->renderToImage(200, 200);

	return 0;
}
