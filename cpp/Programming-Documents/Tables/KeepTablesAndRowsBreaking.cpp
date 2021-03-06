#include "stdafx.h"
#include "examples.h"

#include <system/enumerator_adapter.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Tables/Table.h>
#include <Aspose.Words.Cpp/Model/Tables/RowCollection.h>
#include <Aspose.Words.Cpp/Model/Tables/Row.h>
#include <Aspose.Words.Cpp/Model/Tables/RowFormat.h>
#include <Aspose.Words.Cpp/Model/Tables/Cell.h>
#include <Aspose.Words.Cpp/Model/Text/Paragraph.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphFormat.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphCollection.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeType.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeCollection.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Tables;

namespace
{
    void RowFormatDisableBreakAcrossPages(System::String const &inputDataDir, System::String const &outputDataDir)
    {
        // ExStart:RowFormatDisableBreakAcrossPages
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Table.TableAcrossPage.doc");
        // Retrieve the first table in the document.
        System::SharedPtr<Table> table = System::DynamicCast<Table>(doc->GetChild(NodeType::Table, 0, true));
        // Disable breaking across pages for all rows in the table.
        for (System::SharedPtr<Row> row : System::IterateOver<System::SharedPtr<Row>>(table->get_Rows()))
        {
            row->get_RowFormat()->set_AllowBreakAcrossPages(false);
        }
        System::String outputPath = outputDataDir + u"KeepTablesAndRowsBreaking.RowFormatDisableBreakAcrossPages.doc";
        doc->Save(outputPath);
        // ExEnd:RowFormatDisableBreakAcrossPages
        std::cout << "Table rows breaking across pages for every row in a table disabled successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }

    void KeepTableTogether(System::String const &inputDataDir, System::String const &outputDataDir)
    {
        // ExStart:KeepTableTogether
        System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"Table.TableAcrossPage.doc");
        // Retrieve the first table in the document.
        System::SharedPtr<Table> table = System::DynamicCast<Table>(doc->GetChild(NodeType::Table, 0, true));
        // To keep a table from breaking across a page we need to enable KeepWithNext
        // For every paragraph in the table except for the last paragraphs in the last
        // Row of the table.
        for (System::SharedPtr<Cell> cell : System::IterateOver<System::SharedPtr<Cell>>(table->GetChildNodes(NodeType::Cell, true)))
        {
            // Call this method if table's cell is created on the fly
            // Newly created cell does not have paragraph inside
            cell->EnsureMinimum();
            for (System::SharedPtr<Paragraph> para : System::IterateOver<System::SharedPtr<Paragraph>>(cell->get_Paragraphs()))
            {
                if (!(cell->get_ParentRow()->get_IsLastRow() && para->get_IsEndOfCell()))
                {
                    para->get_ParagraphFormat()->set_KeepWithNext(true);
                }
            }
        }
        System::String outputPath = outputDataDir + u"KeepTablesAndRowsBreaking.KeepTableTogether.doc";
        doc->Save(outputPath);
        // ExEnd:KeepTableTogether
        std::cout << "Table setup successfully to stay together on the same page." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }
}

void KeepTablesAndRowsBreaking()
{
    std::cout << "KeepTablesAndRowsBreaking example started." << std::endl;
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_WorkingWithTables();
    System::String outputDataDir = GetOutputDataDir_WorkingWithTables();
    // The below method shows how to disable rows breaking across pages for every row in a table.
    RowFormatDisableBreakAcrossPages(inputDataDir, outputDataDir);
    // The below method shows how to set a table to stay together on the same page.
    KeepTableTogether(inputDataDir, outputDataDir);
    std::cout << "KeepTablesAndRowsBreaking example finished." << std::endl << std::endl;
}