/*
 * Copyright (C) 2003-2017 Sébastien Helleu <flashcode@flashtux.org>
 *
 * This file is part of WeeChat, the extensible chat client.
 *
 * WeeChat is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * WeeChat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WeeChat.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WEECHAT_UTIL_H
#define WEECHAT_UTIL_H 1

#include <time.h>

#ifdef HAVE_SYS_RESOURCE_H
struct t_rlimit_resource
{
    char *name;                        /* name of resource                  */
    int resource;                      /* value of resource                 */
};
#endif /* HAVE_SYS_RESOURCE_H */

struct t_util_signal
{
    char *name;                        /* name of signal                    */
    int signal;                        /* signal number                     */
};

extern void util_setrlimit ();
extern int util_timeval_cmp (struct timeval *tv1, struct timeval *tv2);
extern long long util_timeval_diff (struct timeval *tv1, struct timeval *tv2);
extern void util_timeval_add (struct timeval *tv, long long interval);
extern const char *util_get_time_string (const time_t *date);
extern int util_signal_search (const char *name);
extern void util_catch_signal (int signum, void (*handler)(int));
extern int util_mkdir_home (const char *directory, int mode);
extern int util_mkdir (const char *directory, int mode);
extern int util_mkdir_parents (const char *directory, int mode);
extern void util_exec_on_files (const char *directory, int recurse_subdirs,
                                int hidden_files,
                                void (*callback)(void *data,
                                                 const char *filename),
                                void *callback_data);
extern char *util_search_full_lib_name (const char *filename,
                                        const char *sys_directory);
extern char *util_file_get_content (const char *filename);
extern int util_version_number (const char *version);
extern void util_get_uptime (time_t *total_seconds, int *days,
                             int *hours, int *minutes, int *seconds);

#endif /* WEECHAT_UTIL_H */
