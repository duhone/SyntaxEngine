// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYNTAXDATABASE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SYNTAXDATABASE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#ifdef SYNTAXDATABASE_EXPORTS
#define SYNTAXDATABASE_API __declspec(dllexport)
#else
#define SYNTAXDATABASE_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <memory>
#include "Singleton.h"
#include "BinaryReader.h"
#include "boost/shared_ptr.hpp"
#include "..\SyntaxMath\Vector.h"
#include "..\SyntaxMath\Rectangle.h"
#include "..\SyntaxMath\Color.h"
#include "Guid.h"

namespace Syntax
{
	namespace Database
	{
		class ISerializable;

		class SYNTAXDATABASE_API IRecordData
		{
		public:
			virtual ~IRecordData() {};
			//! Returns true if currently compressing.
			virtual bool CompressingMode() const = 0;
			//! Set whether to compress any future data sent to the writer.
			virtual void CompressingMode(bool compressing,unsigned int compresedSize) = 0;
			//! Writes binary data out to the file.
			virtual void Read(char* data,int size) = 0;
			//! Reads a bool out to the file.
			virtual IRecordData& operator>>(bool &data) = 0;
			//! Reads a char out to the file.
			virtual IRecordData& operator>>(char &data) = 0;
			//! Reads a short out to the file.
			virtual IRecordData& operator>>(short &data) = 0;
			//! Reads a long out to the file.
			virtual IRecordData& operator>>(long &data) = 0;
			//! Reads a long long out to the file.
			virtual IRecordData& operator>>(long long &data) = 0;
			//! Reads a float out to the file.
			virtual IRecordData& operator>>(float &data) = 0;
			//! Reads a double out to the file.
			virtual IRecordData& operator>>(double &data) = 0;
			//! Reads a unsigned char out to the file.
			virtual IRecordData& operator>>(unsigned char &data) = 0;
			//! Reads a unsigned short out to the file.
			virtual IRecordData& operator>>(unsigned short &data) = 0;
			//! Reads a unsigned long out to the file.
			virtual IRecordData& operator>>(unsigned long &data) = 0;
			//! Reads a unsigned long long out to the file.
			virtual IRecordData& operator>>(unsigned long long &data) = 0;
			//! Reads a wstring out to the file.
			virtual IRecordData& operator>>(std::wstring &data) = 0;
			//! Reads a pair<wstring,wstring> out to the file. Convenience function. Just writes the 2 strings out one after the other.
			virtual IRecordData& operator>>(std::pair<std::wstring,std::wstring> &data) = 0;
			//! Reads a ISerializable out to the file.
			virtual IRecordData& operator>>(Syntax::Utility::ISerializable &data) = 0;
			//! Reads a ISerializable out to the file.
			virtual IRecordData& operator>>(Syntax::Utility::ISerializable *data) = 0;
			//! Reads a Vector4F out to the file.
			virtual IRecordData& operator>>(Syntax::Math::Vector4F &data) = 0;
			//! Reads a RectangleI out to the file.
			virtual IRecordData& operator>>(Syntax::Math::RectangleI &data) = 0;
			//! Reads a Color32 out to the file.
			virtual IRecordData& operator>>(Syntax::Math::Color32 &data) = 0;
			//! Reads a Guid out to the file.
			virtual IRecordData& operator>>(Syntax::Utility::Guid &data) = 0;
		protected:
			IRecordData() {};
			IRecordData(const IRecordData* arg) {};
			const IRecordData& operator=(const IRecordData& arg);
		};

		class SYNTAXDATABASE_API IRecord
		{
		public:
			virtual const Syntax::Utility::Guid& ID() const = 0;
			virtual unsigned long ChildCount() const = 0;
			virtual const std::vector<const IRecord*>& GetChildren() const = 0;
			virtual const IRecord* const GetRecord(const Syntax::Utility::Guid& key) const = 0;
			virtual std::auto_ptr<IRecordData> GetData() const = 0;
		protected:
			IRecord() {};
			IRecord(const IRecord* other) {};
			const IRecord& operator=(const IRecord& arg);
			virtual ~IRecord() {};
		};

		class SYNTAXDATABASE_API ISyntaxDatabase
		{
		public:
			virtual const IRecord* const GetRoot() const = 0;
			virtual const IRecord* const GetRecord(const Syntax::Utility::Guid& key) const = 0;
			virtual void MergeFile(std::wstring fileName)= 0;
			virtual void Release() = 0;
		protected:
			ISyntaxDatabase() {};
			ISyntaxDatabase(const ISyntaxDatabase* other) {};
			const ISyntaxDatabase& operator=(const ISyntaxDatabase& arg);
			virtual ~ISyntaxDatabase() {};
		};

		class SYNTAXDATABASE_API SyntaxDatabaseFactory : public Syntax::Utility::Singleton<SyntaxDatabaseFactory>
		{
			friend Syntax::Utility::Singleton<SyntaxDatabaseFactory>;
		public:
			ISyntaxDatabase* CreateDatabase(const std::wstring& fileName);
		private:
			SyntaxDatabaseFactory(void) {};
			virtual ~SyntaxDatabaseFactory(void) {};
		};
	}
}

//extern SYNTAXDATABASE_API int nSyntaxDatabase;

//SYNTAXDATABASE_API int fnSyntaxDatabase(void);
