// guanfud.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping killer;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(killer) )
		killer= ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "guanfud"; }

int delete_killer(string name)
{
	map_delete(killer, name);
	save();
	return 1;
}

int add_killer(string name, int gold)
{
	if(undefinedp(killer[name]))
		killer[name] = gold;
	else
		killer[name] += gold;

	save();
	return killer[name];
}

string *query_names()
{
	return keys(killer);
}

mixed set_killer(string prop, mixed data)
{
	if( !mapp(killer ) ) killer = ([]);

	if( strsrch(prop, '/')!=-1 )
	{
		_set( killer , explode(prop, "/"), data );
		save();
		return 1;
	}
	killer[prop] = data;
	save();
	return 1;
}

mixed query_killer(string prop)
{
	mixed data;

	if( !mapp(killer) ) return 0;

	if( undefinedp(killer[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(killer, explode(prop, "/"));
	else
		data = killer[prop];

	return data;
}
