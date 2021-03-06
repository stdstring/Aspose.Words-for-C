#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Text/Range.h>
#include <Aspose.Words.Cpp/Model/Sections/SectionCollection.h>
#include <Aspose.Words.Cpp/Model/Sections/Section.h>
#include <Aspose.Words.Cpp/Model/Sections/PageSetup.h>
#include <Aspose.Words.Cpp/Model/Nodes/Node.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Bookmarks/BookmarkStart.h>
#include <Aspose.Words.Cpp/Model/Bookmarks/BookmarkEnd.h>
#include <Aspose.Words.Cpp/Model/Bookmarks/BookmarkCollection.h>
#include <Aspose.Words.Cpp/Model/Bookmarks/Bookmark.h>

#include "Common.h"

using namespace Aspose::Words;

namespace
{
    typedef std::vector<System::SharedPtr<Node>> TNodePtrVector;
}

void ExtractContentBetweenBookmark()
{
    std::cout << "ExtractContentBetweenBookmark example started." << std::endl;
    // ExStart:ExtractContentBetweenBookmark
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_WorkingWithDocument();
    System::String outputDataDir = GetOutputDataDir_WorkingWithDocument();

    System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"TestFile.doc");

    System::SharedPtr<Section> section = doc->get_Sections()->idx_get(0);
    section->get_PageSetup()->set_LeftMargin(70.85);

    // Retrieve the bookmark from the document.
    System::SharedPtr<Bookmark> bookmark = doc->get_Range()->get_Bookmarks()->idx_get(u"Bookmark1");

    // We use the BookmarkStart and BookmarkEnd nodes as markers.
    System::SharedPtr<BookmarkStart> bookmarkStart = bookmark->get_BookmarkStart();
    System::SharedPtr<BookmarkEnd> bookmarkEnd = bookmark->get_BookmarkEnd();

    // Firstly extract the content between these nodes including the bookmark. 
    TNodePtrVector extractedNodesInclusive = ExtractContent(bookmarkStart, bookmarkEnd, true);
    System::SharedPtr<Document> dstDoc = GenerateDocument(doc, extractedNodesInclusive);
    System::String inclusiveOutputPath = outputDataDir + u"ExtractContentBetweenBookmark.Inclusive.doc";
    dstDoc->Save(inclusiveOutputPath);
    std::cout << "File saved at " << inclusiveOutputPath.ToUtf8String() << std::endl;

    // Secondly extract the content between these nodes this time without including the bookmark.
    TNodePtrVector extractedNodesExclusive = ExtractContent(bookmarkStart, bookmarkEnd, false);
    dstDoc = GenerateDocument(doc, extractedNodesExclusive);
    System::String exclusiveOutputPath = outputDataDir + u"ExtractContentBetweenBookmark.Exclusive.doc";
    dstDoc->Save(exclusiveOutputPath);
    std::cout << "File saved at " << exclusiveOutputPath.ToUtf8String() << std::endl;
    // ExEnd:ExtractContentBetweenBookmark
    std::cout << "Extracted content between bookmarks successfully." << std::endl;
    std::cout << "ExtractContentBetweenBookmark example finished." << std::endl << std::endl;
}
