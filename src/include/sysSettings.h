//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2004, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// sysSettings.h - Settings handling class
//
//////////////////////////////////////////////////////////////////////////

#ifndef SYSSETTINGS_H
#define SYSSETTINGS_H

// wxWindows headers
#include <wx/wx.h>
#include <wx/config.h>

// App headers
#include "pgAdmin3.h"

// Class declarations
class sysSettings : public wxConfig
{
public:
    sysSettings(const wxString& name);
    ~sysSettings();

    // frmQueryBuilder size/position
    wxSize GetFrmQueryBuilderSize();
    wxPoint GetFrmQueryBuilderPos();
	void SetFrmQueryBuilderPos(wxPoint pos);
	void SetFrmQueryBuilderSize(wxSize size);

    // Tip Of The Day
    bool GetShowTipOfTheDay() const { return showTipOfTheDay; }
    void SetShowTipOfTheDay(const bool newval);
    int GetNextTipOfTheDay() const { return nextTipOfTheDay; }
    void SetNextTipOfTheDay(const int newval);

    // Log
    wxString GetLogFile() const { return logFile; }
    void SetLogFile(const wxString& newval);
    int GetLogLevel() const { return logLevel; }
    void SetLogLevel(const int newval);

    // Last connection
    wxString GetLastDescription() const { return lastDescription; }
    void SetLastDescription(const wxString& newval);
    wxString GetLastServer() const { return lastServer; }
    void SetLastServer(const wxString& newval);
    wxString GetLastDatabase() const { return lastDatabase; }
    void SetLastDatabase(const wxString& newval);
    wxString GetLastUsername() const { return lastUsername; }
    void SetLastUsername(const wxString& newval);
    int GetLastPort() const { return lastPort; }
    void SetLastPort(const int newval);
    int GetLastSSL() const { return lastSSL; }
    void SetLastSSL(const int newval);
    long GetMaxRows() const { return maxRows; }
    void SetMaxRows(const long l) { maxRows=l; }
    long GetMaxColSize() const { return maxColSize; }
    void SetMaxColSize(const long l) { maxColSize=l; }
    bool GetAskSaveConfirmation() const { return askSaveConfirmation; }
    void SetAskSaveConfirmation(const bool b) { askSaveConfirmation=b; }
    bool GetConfirmDelete() const { return confirmDelete; }
    void SetConfirmDelete(const bool b) { confirmDelete=b; }

    wxString GetSqlHelpSite() const { return sqlHelpSite; }
    void SetSqlHelpSite(const wxString& s) { sqlHelpSite = s; }
    wxString GetProxy() const { return proxy; }
    void SetProxy(const wxString& s);

    bool GetExplainVerbose() const { return explainVerbose; }
    void SetExplainVerbose(const bool b) { explainVerbose=b; }
    bool GetExplainAnalyze() const { return explainAnalyze; }
    void SetExplainAnalyze(const bool b) { explainAnalyze=b; }

    bool GetShowUsersForPrivileges() const { return showUsersForPrivileges; }
    void SetShowUsersForPrivileges(const bool b) { showUsersForPrivileges=b; }

    // Show System Objects
    bool GetShowSystemObjects() const { return showSystemObjects; }
    void SetShowSystemObjects(const bool newval);

    // Auto Row Count
    long GetAutoRowCountThreshold() const { return autoRowCountThreshold; }
    void SetAutoRowCountThreshold(const long l) { autoRowCountThreshold=l; }

    // Sticky SQL
    bool GetStickySql() const { return stickySql; }
    void SetStickySql(const bool newval);

    // DoubleClick for Properties
    bool GetDoubleClickProperties() const { return doubleClickProperties; }
    void SetDoubleClickProperties(const bool newval);

    wxString GetSearchPath() const { return searchPath; }
    void SetSearchPath(const wxString &s) { searchPath=s; }

    bool GetUnicodeFile() const { return unicodeFile; }
    void SetUnicodeFile(const bool b) {unicodeFile = b; }

    wxFont GetSQLFont() const { return wxFont(sqlFontPointSize, sqlFontFamily, sqlFontStyle, sqlFontWeight, false, sqlFontFace); }
    wxFont GetSystemFont() const { return systemFont; }
    void SetFont(const wxFont &font);
    void SetSQLFont(const wxFont &font);
    wxString GetCanonicalLanguage() const { return canonicalLanguage; }

    bool Write(const wxString &key, const wxString &value) { return wxConfig::Write(key, value); }
    bool Write(const wxString &key, long value) { return wxConfig::Write(key, value); }
    bool Write(const wxString &key, const wxPoint &value);
    bool Write(const wxString &key, const wxSize &value);
    bool Write(const wxString &key, const wxSize &size, const wxPoint &point)
        { Write(key, point); Write(key, size); return true;}

    bool Read(const wxString& key, wxString* str, const wxString& defaultVal) const
        { return wxConfig::Read(key, str, defaultVal); }
    bool Read(const wxString& key, bool* str, bool defaultVal) const
        { return wxConfig::Read(key, str, defaultVal); }
    bool Read(const wxString& key, int* i, int defaultVal) const
        { return wxConfig::Read(key, i, defaultVal); }
    bool Read(const wxString& key, long* l, long defaultVal) const
        { return wxConfig::Read(key, l, defaultVal); }
    wxString Read(const wxString& key, const wxString &defaultVal) const
        { return wxConfig::Read(key, defaultVal); }
    long Read(const wxString& key, long defaultVal) const
        { return wxConfig::Read(key, defaultVal); }
    wxPoint Read(const wxString& key, const wxPoint &defaultVal) const;
    wxSize Read(const wxString& key, const wxSize &defaultVal) const;




private:

    wxFont systemFont; 

    // Tip Of The Day
    bool showTipOfTheDay;
    int nextTipOfTheDay;

    // Log
    wxString logFile;
    int logLevel;

    // Last connection
    wxString lastDescription;
    wxString lastServer;
    wxString lastDatabase;
    wxString lastUsername;
    int lastPort, lastSSL;

    // Show System Objects
    bool showSystemObjects;

    bool explainVerbose, explainAnalyze;

    wxString sqlHelpSite, proxy;
    wxString canonicalLanguage;
    bool showUsersForPrivileges;
    bool askSaveConfirmation;
    bool confirmDelete;
    long maxRows, maxColSize, autoRowCountThreshold;
    bool stickySql, unicodeFile;
    bool doubleClickProperties;

    wxString searchPath;

    int fontPointSize, fontFamily, fontStyle, fontWeight;
    wxString fontFace;
    int sqlFontPointSize, sqlFontFamily, sqlFontStyle, sqlFontWeight;
    wxString sqlFontFace;
};

#endif
