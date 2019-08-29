#include "stdafx.h"
#include "examples.h"

#include <Model/Document/Document.h>
#include <Model/Sections/Section.h>
#include <Model/Sections/Body.h>
#include <Model/Text/Paragraph.h>
#include <Model/Text/ParagraphFormat.h>
#include <Model/Styles/Style.h>
#include <Model/Styles/StyleCollection.h>


using namespace Aspose::Words;

namespace
{
    void ReadMarkdownDocument(System::String const &dataDir)
    {
        // ExStart: ReadMarkdownDocument
        // This is Markdown document that was produced in example of UC3.
        System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"QuotesExample.md");

        // Let's remove Heading formatting from a Quote in the very last paragraph.
        System::SharedPtr<Paragraph> paragraph = doc->get_FirstSection()->get_Body()->get_LastParagraph();
        paragraph->get_ParagraphFormat()->set_Style(doc->get_Styles()->idx_get(u"Quote"));

        System::String outputPath = dataDir + GetOutputFilePath(u"WorkingWithMarkdownFeatures.ReadMarkdownDocument.md");
        doc->Save(outputPath);
        // ExEnd: ReadMarkdownDocument
        std::cout << "Read Markdown Document!" << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }
}

void WorkingWithMarkdownFeatures()
{
    std::cout << "WorkingWithMarkdownFeatures example started." << std::endl;
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithDocument();
    ReadMarkdownDocument(dataDir);
    std::cout << "WorkingWithMarkdownFeatures example finished." << std::endl << std::endl;
}