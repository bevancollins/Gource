/*
    Copyright (C) 2009 Andrew Caudwell (acaudwell@gmail.com)

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GITLOG_RAW_H
#define GITLOG_RAW_H

#include "commitlog.h"

#ifndef _WIN32
#include <unistd.h>
#endif

extern std::string gGourceGitRawLogCommand;

class GitRawCommitLog : public RCommitLog {
protected:
    bool parseCommit(RCommit& commit);
public:
    GitRawCommitLog(const std::string& logfile);
};

#endif

