#include "include/enquire_fuben.h"
#include <localtime.h>

int enquire_fuben(object who, object fb_mem)
{
	int i, last_time;
	object *team;
	
	if (!(team = who->query_team()))
	{
		write("�㻹û�м��뵽�����С�\n");
		return 0;
	}
	
	if ( team[0] != who) 
	{
		write("ֻ�ж���������ܿ���������\n");
		return 0;
	}
	
	if (sizeof(team) < 1)
	{
		write("��������˲�������һ�ˡ�\n");
		return 0;
	}
	
	if (sizeof(team) > 5)
	{
		write("��������˲��ܳ������\n");
		return 0;
	}
	
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("combat_exp") < 500000)
		{
			write("��Ķ����м�������Ϊ������ʮ��\n");
			return 0;
		}
	
	}
	
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("renzheng") < 1)
		{
			write("��Ķ����м�����û�н�����֤��\n");
			return 0;
		}
	}
	
	for (i=0;i<sizeof(team);i++)
	{
		if (!team[i]){
			write("��Ķ�����������⣬���ɢ�������齨��\n");
			return 0;
		}
		
		if (!present(team[i],environment(who))){
			write("�ף���ô�����˲�ȫ����"+team[i]->query("name")+"��ôû����\n");
			return 0;
		}
		
		if (!interactive(team[i])) 
		{
			write(team[i]->query("name")+"���ڲ����ߣ����������˰ɡ�\n");
			return 0;
		}
		
		last_time = team[i]->query("fuben_jiaofei/last_time");
		if ((last_time/86400) != (time()/86400) || !team[i]->query("delete_sign"))
		{
			team[i]->delete("fuben_jiaofei/count");
			team[i]->set("delete_sign", 1);
		}
		/*if (((localtime(last_time)[LT_MON] != localtime(time())[LT_MON])) && ((localtime(last_time)[LT_MDAY] != localtime(time())[LT_MDAY])))
		{
			team[i]->delete("fuben_jiaofei/count");
		}*/
	}
	
	return 1;
}

int check_skill(object *team)
{
	int get_max_level, max_level = 0, min_level = 0;
	mapping skills_map;
	string *skills, skill_temp;
	object temp;
	
	foreach(temp in team)
	{
		get_max_level = 0;
		if(!(skills_map = temp->query_skills()))
		{
			get_max_level = 0;
		}
		else
		{
    		skills = filter_array(keys(skills_map), (: SKILL_D($1)->type() != "knowledge" :));
    		foreach(skill_temp in skills)
    		{
    			if (get_max_level < skills_map[skill_temp])	get_max_level = skills_map[skill_temp];
    		}
		}
		if (!min_level)	min_level = get_max_level;
		if (min_level > get_max_level)	min_level = get_max_level;
		if (max_level < get_max_level)	max_level = get_max_level;
	}
	if ((max_level - min_level) > 50)
		return 0;
	else
		return 1;
}