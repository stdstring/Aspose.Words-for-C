#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Sections/SectionCollection.h>
#include <Aspose.Words.Cpp/Model/Sections/Section.h>
#include <Aspose.Words.Cpp/Model/Sections/PageSetup.h>
#include <Aspose.Words.Cpp/Model/Sections/TextColumnCollection.h>

using namespace Aspose::Words;

void SectionsAccessByIndex()
{
    std::cout << "SectionsAccessByIndex example started." << std::endl;
    // ExStart:SectionsAccessByIndex
    // The path to the documents directory.
    System::String inputDataDir = GetInputDataDir_WorkingWithSections();
    System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Document.doc");
    System::SharedPtr<Section> section = doc->get_Sections()->idx_get(0);
    section->get_PageSetup()->set_LeftMargin(90);
    // 3.17 cm
    section->get_PageSetup()->set_RightMargin(90);
    // 3.17 cm
    section->get_PageSetup()->set_TopMargin(72);
    // 2.54 cm
    section->get_PageSetup()->set_BottomMargin(72);
    // 2.54 cm
    section->get_PageSetup()->set_HeaderDistance(35.4);
    // 1.25 cm
    section->get_PageSetup()->set_FooterDistance(35.4);
    // 1.25 cm
    section->get_PageSetup()->get_TextColumns()->set_Spacing(35.4);
    // 1.25 cm
    // ExEnd:SectionsAccessByIndex
    std::cout << "Section at 0 index have text \"" << section->GetText().ToUtf8String() << "\"" << std::endl;
    std::cout << "SectionsAccessByIndex example finished." << std::endl << std::endl;
}