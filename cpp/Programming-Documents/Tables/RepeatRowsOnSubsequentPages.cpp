#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Document/DocumentBuilder.h>
#include <Aspose.Words.Cpp/Model/Tables/Table.h>
#include <Aspose.Words.Cpp/Model/Tables/RowFormat.h>
#include <Aspose.Words.Cpp/Model/Tables/CellFormat.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphAlignment.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphFormat.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Tables;

void RepeatRowsOnSubsequentPages()
{
    std::cout << "RepeatRowsOnSubsequentPages example started." << std::endl;
    // ExStart:RepeatRowsOnSubsequentPages
    // The path to the documents directory.
    System::String outputDataDir = GetOutputDataDir_WorkingWithTables();
    System::SharedPtr<Document> doc = System::MakeObject<Document>();
    System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);
    System::SharedPtr<Table> table = builder->StartTable();
    builder->get_RowFormat()->set_HeadingFormat(true);
    builder->get_ParagraphFormat()->set_Alignment(ParagraphAlignment::Center);
    builder->get_CellFormat()->set_Width(100);
    builder->InsertCell();
    builder->Writeln(u"Heading row 1");
    builder->EndRow();
    builder->InsertCell();
    builder->Writeln(u"Heading row 2");
    builder->EndRow();
    builder->get_CellFormat()->set_Width(50);
    builder->get_ParagraphFormat()->ClearFormatting();
    // Insert some content so the table is long enough to continue onto the next page.
    for (int32_t i = 0; i < 50; i++)
    {
        builder->InsertCell();
        builder->get_RowFormat()->set_HeadingFormat(false);
        builder->Write(u"Column 1 Text");
        builder->InsertCell();
        builder->Write(u"Column 2 Text");
        builder->EndRow();
    }
    System::String outputPath = outputDataDir + u"RepeatRowsOnSubsequentPages.doc";
    // Save the document to disk.
    doc->Save(outputPath);
    // ExEnd:RepeatRowsOnSubsequentPages
    std::cout << "Table build successfully which include heading rows that repeat on subsequent pages." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "RepeatRowsOnSubsequentPages example finished." << std::endl << std::endl;

}