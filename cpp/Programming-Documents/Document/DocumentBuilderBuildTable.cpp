#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Text/TextOrientation.h>
#include <Aspose.Words.Cpp/Model/Text/HeightRule.h>
#include <Aspose.Words.Cpp/Model/Tables/Table.h>
#include <Aspose.Words.Cpp/Model/Tables/RowFormat.h>
#include <Aspose.Words.Cpp/Model/Tables/Row.h>
#include <Aspose.Words.Cpp/Model/Tables/CellVerticalAlignment.h>
#include <Aspose.Words.Cpp/Model/Tables/CellFormat.h>
#include <Aspose.Words.Cpp/Model/Tables/Cell.h>
#include <Aspose.Words.Cpp/Model/Tables/AutoFitBehavior.h>
#include <Aspose.Words.Cpp/Model/Document/DocumentBuilder.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Tables;

void DocumentBuilderBuildTable()
{
    std::cout << "DocumentBuilderBuildTable example started." << std::endl;
    // ExStart:DocumentBuilderBuildTable
    // The path to the documents directory.
    System::String outputDataDir = GetOutputDataDir_WorkingWithDocument();
    // Initialize document.
    System::SharedPtr<Document> doc = System::MakeObject<Document>();
    System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);

    System::SharedPtr<Table> table = builder->StartTable();

    // Insert a cell
    builder->InsertCell();
    // Use fixed column widths.
    table->AutoFit(AutoFitBehavior::FixedColumnWidths);

    builder->get_CellFormat()->set_VerticalAlignment(CellVerticalAlignment::Center);
    builder->Write(u"This is row 1 cell 1");

    // Insert a cell
    builder->InsertCell();
    builder->Write(u"This is row 1 cell 2");

    builder->EndRow();

    // Insert a cell
    builder->InsertCell();

    // Apply new row formatting
    builder->get_RowFormat()->set_Height(100);
    builder->get_RowFormat()->set_HeightRule(HeightRule::Exactly);
    
    builder->get_CellFormat()->set_Orientation(TextOrientation::Upward);
    builder->Writeln(u"This is row 2 cell 1");

    // Insert a cell
    builder->InsertCell();
    builder->get_CellFormat()->set_Orientation(TextOrientation::Downward);
    builder->Writeln(u"This is row 2 cell 2");

    builder->EndRow();

    builder->EndTable();
    System::String outputPath = outputDataDir + u"DocumentBuilderBuildTable.doc";
    doc->Save(outputPath);
    // ExEnd:DocumentBuilderBuildTable
    std::cout << "Table build successfully using DocumentBuilder." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "DocumentBuilderBuildTable example finished." << std::endl << std::endl;
}
