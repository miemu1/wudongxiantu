// ls.c
// updated by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int filter_list(mixed ob, string path, object user);
int sort_list(mixed ob1, mixed ob2);
string check_files(string str,string path);
int main(object me, string arg)
{
 	int mark_loaded;
	int i, j, w, col;
	string dir;
	string path,paths,choose;
	int opt_l;
	mixed *file;
	string result,lastdir,*lastdirs;
	paths = "/";
	if (arg&&strsrch(arg,".c")!=-1)
	{
	choose= ZJOBLONG+"����ԶԸ��ļ��������²���\n";
	choose+= ZJOBACTS2+ZJMENUF(1,1,8,35);
	if (arg&&strsrch(arg,"/d/")!=-1)
	choose += "ȥ����ط�:goto "+arg+ZJSEP;
		choose += "����鿴:more "+arg+ZJSEP;
		choose += "���±���:update "+arg+ZJSEP;
		//choose += "����������:dest -c "+arg+ZJSEP;
			choose += "������Ʒ:clone "+arg+ZJSEP;
		//choose += "����ɾ��:rm "+arg+ZJSEP;
	tell_object(me,choose+"\n");
	return 1;
	}
	/*
	�����ļ�
	*/
	if (arg)
	{
	lastdir = "";
	lastdirs = explode(arg,"/");
	j = sizeof(lastdirs);
	for(i=0;i < j;i++)
	{
	if (sizeof(lastdirs[i]))
	paths += 	HIW+ZJURL("cmds:ls " + lastdirs[i])ZJSIZE(20)+lastdirs[i]+NOR+"/";
	if (i <= j-2&&sizeof(lastdirs[i]))
	lastdir += lastdirs[i]+"/";	
	}
//	paths += 	HIW+ZJURL("cmds:ls " + lastdirs[j+1])ZJSIZE(20)+lastdirs[j+1]+NOR+"/";
	}
	else
	{
	lastdir = "/";
	}

	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (arg)
	{
		if (arg == "-l")
		{
			opt_l = 1;
			arg = 0;
		} else
		if (sscanf(arg, "%s -l", arg) || sscanf(arg, "-l %s", arg))
		{
			opt_l = 1;
		} else
			opt_l = 0;
	}

	dir = resolve_path(me->query("cwd"), arg);

	if (me != this_player(1))
		return notify_fail("���ǵ�ǰʹ���߽��в�����\n");

	seteuid(getuid());
	if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/') dir += "/";

	if (file_size(dir) == -2)
	{
		path = dir;
	} else
	{
		string *p;
		p = explode(dir, "/");
		if (sizeof(p) >= 2)
		{
			p = p[0..sizeof(p) - 2];
			path = "/" + implode(p, "/") + "/";
		} else
			path = "/";
		p = 0;
	}

	file = get_dir(dir, -1);
	seteuid(geteuid(me));

	if (! sizeof(file))
	{
		if (file_size(dir) == -2)
			return notify_fail(sprintf("Ŀ¼(%s)�ǿյġ�\n", dir));
		else
			return notify_fail(sprintf("û�����Ŀ¼(%s)��\n", dir));
	}

	file = filter_array(file, (: filter_list :), path, me);
	file = sort_array(file, (: sort_list :));

	i = sizeof(file);
	w = 0;
	while (i--)
	{
		if (file[i][1] == -2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
		file[i] += ({ MASTER_OB->valid_write(path + file[i][0], me, "ls") });
	}
	result = "��ǰĿ¼��" + paths + "\n";
//	if (sizeof(lastdir))
	result += HIR+ZJURL("cmds:ls " + lastdir)ZJSIZE(20)+"������һ��Ŀ¼\n"+NOR;
//result+=ZJOBACTS2+ZJMENUF(1,1,8,35);
	if (! sizeof(file))
	{
		write(sprintf("%s    û���κε�����\n\n", result));
		return 1;
	}

	if (opt_l)
	{
		string syntax;
		// name  size  compiled  last_change
		syntax = sprintf("%%s%%-%ds  %%-8s  %%-8s  %%s"NOR"\n", w);
		result += sprintf(syntax, HIG, "NAME", "SIZE", "LOADING", "MODIFIED TIME");
		for(i=0, j = sizeof(file); i<j; i++)
			result += sprintf(syntax,
				(file[i][3] ? WHT : HIR),
				file[i][0],
				(file[i][1] == -2 ? "<Ŀ¼>" : sprintf("%d", file[i][1])),
				((file[i][1] != -2 && find_object(path + file[i][0])) ? "compiled" : "--------"),
				ctime(file[i][2]));
	} else
	{
		col = 70 / (w + 6);
		if (! col) col = 1;
		for (i = 0, j = sizeof(file); i < j; i++)
			result += sprintf(HIM "%s %s%-*s%s" NOR,
				(file[i][1] == -2 ? "<Ŀ¼>" : sprintf("%4dk", (file[i][1] + 1023) / 1024)),
				(file[i][3] ? (file[i][1] == -2 || find_object(path + file[i][0])? HIW:HIW) : HIR),
				w + 1, check_files(file[i][0],path),
				"\n");
	}
	//ZJURL("cmds:walk " + file[i][0])ZJSIZE(30)+ file[i][0]
	result = replace_string(result,"\n",ZJBR);
	write(ZJOBLONG+result+"\n");

	return 1;
}

int filter_list(mixed ob, string path, object user)
{
	return MASTER_OB->valid_read(path + ob[0], user, "ls");
}

int sort_list(mixed ob1, mixed ob2)
{
	if (ob1[1] == -2 && ob2[1] != -2)
		return -1;

	if (ob1[1] != -2 && ob2[1] == -2)
		return 1;

	return strcmp(ob1[0], ob2[0]);
}

string check_files(string str,string path)
{
if (strsrch(str,".c")!=-1)
//return str+":ls "+path+str+ZJSEP;
return ZJURL("cmds:ls " + path + str)ZJSIZE(20)+ str+NOR;
else
return HIY+ZJURL("cmds:ls " + path+str)ZJSIZE(20)+ str+NOR;
//return HIW+str+NOR+":ls "+path+str+ZJSEP;
}
int help(object me)
{
	write(@HELP
ָ���ʽ: ls [-l] [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ����У���ɫ�Ĵ���·�������Ѿ�����������Ӧ��
�ļ�������ɫ�Ĵ�����ͨ���ļ�����ɫ���ʾ��Ը�Ŀ¼���ļ�û��д
��Ȩ�ޡ�-l���������г���ϸ���ϡ�
 
����:
'ls /' ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼��
'ls /adm/*.c -l' ����г�/adm/Ŀ¼����������.c��β���ļ�����ϸ
�����б�
 
HELP );
	return 1;
}
