/* basic info for a file or service object */
CREATE TABLE  Services
(
	ID            		Integer primary key not null,
	ServiceTypeID		Integer  default 0, /* see ServiceTypes table above for ID values. A value of 0 indicates a group resource rather than a service */
	Path 			Text not null,      /* non-file objects should use service name here */
	Name	 		Text default ' ',   /* name of file or object - the combination path and name must be unique for all objects */
	Enabled			Integer default 1,
	Mime			Text default ' ',
	Size			Integer default 0,
	Rank			Integer default 5,
	ParentID		Integer,

	KeyMetadata1		Text,
	KeyMetadata2		Text,
	KeyMetadata3		Text,
	KeyMetadata4		Text,
	KeyMetadata5		Text,
	KeyMetadata6		Integer,
	KeyMetadata7		Integer,
	KeyMetadata8		Integer,
	KeyMetadata9		Text,
	KeyMetadata10		Text,
	KeyMetadata11		Text,

	Icon			Text,
	CanWrite		Integer default 1,
	CanExecute		Integer default 1,

	LanguageId		Integer default 0,
	IsDirectory   		Integer default 0,
    	IsLink        		Integer default 0,
	AuxilaryID		Integer default 0, /* link to Volumes table for files, link to MailSummary table for emails*/
	IndexTime  		Integer default 0, /* should equal st_mtime for file if up-to-date */
	Accessed  		Integer default 0, /* last accessed */
	Offset			Integer default 0, /* last used disk offset for indexable files that always grow (like chat logs) or email offset */
	MD5			Text,

    	unique (Path, Name)
);

CREATE INDEX ServiceTypeIDIndex1 ON Services (ServiceTypeID);

/* child service relationships for a specific group/struct metadata */
CREATE TABLE ChildServices
(
	ParentID            		Integer not null,
	ChildID				Integer not null,
	MetaDataID			Integer not null,

	primary key (ParentID, ChildID, MetaDataID)
);

/* utf-8 based literal metadata. */
CREATE TABLE  ServiceMetaData 
(
	ID			Integer primary key AUTOINCREMENT not null,
	ServiceID		Integer not null,
	MetaDataID 		Integer not null,
	MetaDataValue     	Text,
	MetaDataDisplay		Text,
	MetaDataCollation	Text
);

CREATE INDEX ServiceMetaDataCompoundIndex4 ON ServiceMetaData (ServiceID, MetaDataID, MetaDataDisplay, MetaDataCollation);

/* metadata for all keyword types - keywords are db indexed for fast searching - they are also not processed like other metadata. */
CREATE TABLE  ServiceKeywordMetaData 
(
	ID			Integer primary key AUTOINCREMENT not null,
	ServiceID		Integer not null,
	MetaDataID 		Integer not null,
	MetaDataValue		Text COLLATE NOCASE
);

CREATE INDEX ServiceKeywordMetaDataCompoundIndex ON ServiceKeywordMetaData (ServiceID, MetaDataID, MetaDataValue);

/* metadata for all integer/date types */
CREATE TABLE  ServiceNumericMetaData 
(
	ID			Integer primary key AUTOINCREMENT not null,
	ServiceID		Integer not null,
	MetaDataID 		Integer not null,
	MetaDataValue		Integer not null
);

CREATE INDEX ServiceNumericMetaDataCompoundIndex ON ServiceNumericMetaData (ServiceID, MetaDataID, MetaDataValue);


CREATE TABLE DeletedServices
(
        ID      Integer primary key not null
);
