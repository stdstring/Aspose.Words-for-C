#include "stdafx.h"
#include "examples.h"

#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Fields/Fields/DocumentInformation/FieldAuthor.h>
#include <Aspose.Words.Cpp/Model/Fields/FieldType.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeCollection.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeType.h>
#include <Aspose.Words.Cpp/Model/Text/Paragraph.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Fields;

void InsertAuthorField()
{
    std::cout << "InsertAuthorField example started." << std::endl;
    // ExStart:InsertAuthorField
    // The path to the documents directories.
    System::String inputDataDir = GetInputDataDir_WorkingWithFields();
    System::String outputDataDir = GetOutputDataDir_WorkingWithFields();
    System::SharedPtr<Document> doc = System::MakeObject<Document>(inputDataDir + u"in.doc");
    // Get paragraph you want to append this AUTHOR field to
    System::SharedPtr<Paragraph> para = System::DynamicCast<Paragraph>(doc->GetChildNodes(NodeType::Paragraph, true)->idx_get(1));

    // We want to insert an AUTHOR field like this:
    // { AUTHOR Test1 }

    // Create instance of FieldAuthor class and lets build the above field code
    System::SharedPtr<FieldAuthor> field = System::DynamicCast<FieldAuthor>(para->AppendField(FieldType::FieldAuthor, false));

    // { AUTHOR Test1 }
    field->set_AuthorName(u"Test1");

    // Finally update this AUTHOR field
    field->Update();

    System::String outputPath = outputDataDir + u"InsertAuthorField.doc";
    doc->Save(outputPath);
    // ExEnd:InsertAuthorField
    std::cout << "Author field without document builder inserted successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "InsertAuthorField example finished." << std::endl << std::endl;
}