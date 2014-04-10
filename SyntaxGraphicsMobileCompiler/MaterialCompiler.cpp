#include "StdAfx.h"
#include "MaterialCompiler.h"
#include "BinaryWriterFO.h"
#include "FunctionObjects.h"

using namespace Syntax::Utility;
using namespace Syntax::GraphicsCompiler;
using namespace boost::lambda;
using namespace std;


MaterialCompiler::MaterialCompiler(void)
{
}

MaterialCompiler::~MaterialCompiler(void)
{
}

void MaterialCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	writer << effect;
	writer << (long)textures.size();
	vector<wstring> textureNames;
	for_each(textures.begin(),textures.end(),BinaryWriterFO(writer) );
	writer << (long)properties.size();
	for_each(properties.begin(),properties.end(),BinaryWriterFO(writer) );
	
}