#include "stdafx.h"
#include "examples.h"

#include <Model/Document/Document.h>
#include <Model/Document/DocumentBuilder.h>
#include <Model/Fields/Fields/Other/FieldUnknown.h>
#include <Model/Fields/FieldType.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Fields;

void InsertFieldNone()
{
    std::cout << "InsertFieldNone example started." << std::endl;
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithFields();
    // ExStart:InsertFieldNone
    System::SharedPtr<Document> doc = System::MakeObject<Document>();
    System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);
    System::SharedPtr<FieldUnknown> field = System::DynamicCast<FieldUnknown>(builder->InsertField(FieldType::FieldNone, false));

    System::String outputPath = dataDir + GetOutputFilePath(u"InsertFieldNone.docx");
    doc->Save(outputPath);
    // ExEnd:InsertFieldNone
    std::cout << "Inserted field in the document successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    std::cout << "InsertFieldNone example finished." << std::endl << std::endl;
}