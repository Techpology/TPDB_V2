#ifndef TPDB_GLOBAL_H
#define TPDB_GLOBAL_H
#include <stdio.h>

#define TP_TRUE 1
#define TP_FALSE 0

#define TP_EXIT 1
#define TP_IGNORE 0

#define TP_ROW_EXT ".tdf"

enum TPTable_Column_Types
{
	TP_INT,
	TP_FLOAT,
	TP_STRING,
	TP_CHAR,
	TP_FKEY
};

typedef struct
{
	char *TableName;
	int _ID;
} TPForeignKey;

typedef struct TPDatabase TPDatabase;

typedef struct
{
	int _ID;
	int ValCount;
	char **Values;
} TPTable_Row;

typedef struct
{
	TPDatabase *ParentDatabase;
	int _ID;
	char *Name;
	char *Path;

	int ColCount;
	int RowCount;

	int ColumnsToIndexCount;
	int *ColumnsToIndex;

	enum TPTable_Column_Types *ColumnTypes;
	TPTable_Row **Rows;

	int RowsOnDemand;
} TPTable;

struct TPDatabase
{
	int _ID;
	char *Name;
	char *Path;
	char *ConfigPath;
	size_t TablesCount;
	TPTable **Tables;
};

#endif