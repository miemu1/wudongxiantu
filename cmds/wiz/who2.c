// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,list,dir,*dirs,*attr,file,*files;
	string txt1,txt2,txt3;
	int i,k;
	mapping obs;
	object env;
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (!wizardp(me))
		return 0;
	seteuid(geteuid(me));

	if(!arg)
	{
		str = ZJOBLONG"����ɾ���ĸ�����ĳ�����"ZJBR+ZJBR;
		str += "����������������"ZJURL("cmds:who2 north")+ZJSIZE(15)"����"NOR+ZJBR+ZJBR;
		str += "��"ZJURL("cmds:who2 west")+ZJSIZE(15)"����"NOR"��������������������";
		str += ZJURL("cmds:who2 east")+ZJSIZE(15)"����"NOR+ZJBR+ZJBR;
		str += "����������������"ZJURL("cmds:who2 south")+ZJSIZE(15)"����"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}

	env = environment(me);
	dirs = explode(base_name(env),"/");
	dirs = dirs[0..(sizeof(dirs)-2)];
	dir = "/"+implode(dirs,"/")+"/";
	obs = env->query("exits");
	if(!mapp(obs)||!obs[arg])
		return notify_fail("�Ǹ�����û�г�����\n");

	if(obs[arg]->query("objects")&&sizeof(keys(obs[arg]->query("objects")))>0)
		return notify_fail("���Ƚ���"+obs[arg]->query("short")+"ɾ��NPC���úͶ���������ӡ�\n");
	if(obs[arg]->query("exits")&&sizeof(keys(obs[arg]->query("exits")))>1)
		return notify_fail(obs[arg]->query("short")+"���ӵ�����������������ֱ��ɾ����\n");
	if(sizeof(all_inventory(find_object(obs[arg]))))
		return notify_fail(obs[arg]->query("short")+"����δ�����������������ȥ�����\n");

	dirs = keys(obs);
	
	list = read_file(base_name(env)+".c");
	if(sscanf(list,"%sset(\"exits\"%*s]));%s",txt1,txt2)==3)
	{
		rm(obs[arg]+".c");
		map_delete(obs,arg);
		files = keys(obs);
		list = txt1+"set(\"exits\", ([\n";
		for(i=0;i<sizeof(files);i++)
		{
			list += "		\""+files[i]+"\" : \""+obs[files[i]]+"\",\n";
		}
		list += "	]));"+txt2;
		list = replace_string(list,"\""+dir,"__DIR__\"");
		write_file(base_name(env)+".c",list,1);
		tell_object(me,ZJFORCECMD("update here"));
		tell_object(me,ZJFORCECMD("look"));
		write(HIY"����ɾ���ɹ�������"NOR"\n");
	}
	else
		write(HIY"�����������ݶ�ȡʧ�ܣ�ɾ��ʧ�ܡ�����"NOR"\n");

	return 1;
}

void update_here(object me)
{
	me->force_me("update here");
	me->force_me("look");
}
