#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Importing/ImportFormatMode.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>

using namespace Aspose::Words;

void BaseDocument()
{
    std::cout << "BaseDocument example started." << std::endl;
    // ExStart:BaseDocument
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_JoiningAndAppending();
    System::String outputDataDir = GetOutputDataDir_JoiningAndAppending();

    // ExStart
    // ExId:AppendDocument_BaseDocument
    // ExSummary:Shows how to remove all content from a document before using it as a base to append documents to.
    // Use a blank document as the destination document.
    System::SharedPtr<Document> dstDoc = System::MakeObject<Document>();
    System::SharedPtr<Document> srcDoc = System::MakeObject<Document>(inputDataDir + u"TestFile.Source.doc");

    // The destination document is not actually empty which often causes a blank page to appear before the appended document
    // This is due to the base document having an empty section and the new document being started on the next page.
    // Remove all content from the destination document before appending.
    dstDoc->RemoveAllChildren();

    dstDoc->AppendDocument(srcDoc, ImportFormatMode::KeepSourceFormatting);
    System::String outputPath = outputDataDir + u"BaseDocument.doc";
    dstDoc->Save(outputPath);
    // ExEnd:BaseDocument
    std::cout << "Document appended successfully with all content removed from the destination document." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "BaseDocument example finished." << std::endl << std::endl;
}
