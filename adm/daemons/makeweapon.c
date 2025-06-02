#include <ansi.h>
#include <skill.h>
inherit F_DBASE;

int time;
int wwtime;
int saytime;
int jobTime;

///void call_time();
void add_exp(object me,object env);
void add_skill(object me,object env);
void add_weiwang(object me,int index);
void dest_weapon();
void check_job();

//��������ʼ
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "�һ�");
	CHANNEL_D->do_channel( this_object(), "sys", "�һ��¼�ϵͳ�Ѿ�������\n");
	//���ʱ��
	time = time()+300;
	//call_time();
	//dest_weapon();
}

//���������������
int call_do_training(object me,string arg)
{
	object *users,env;
	int i,size,index;

	if(!arg)
	{
		tell_object(me,"��ʼʧ�ܡ�\n");
			return 0;
	}

	switch(arg)
	{
		/*case "over" :
			if(query("xunlian"))
			{
				delete("xunlian");
				remove_call_out("add_exp");
				remove_call_out("add_skill");
				tell_object(me,"�رճɹ���\n");
				return 1;
			}
			else
			{
					tell_object(me,"��û������ģʽ��\n");
					return 1;
			}
			break;*/
		case "exp" :
		case "skill" :
			if(me->query_temp("xunlian")==1)
			{
				tell_object(me,"�����ظ���������ģʽ��\n");
				return 1;
			}
			env = environment(me);
			if(!objectp(env)) return 1;
			me->set_temp("xunlian",1);
			if(arg == "exp")
				add_exp(me,env);
				add_skill(me,env);

			break;
		default :
			if(query_temp("xunlian"))
			{
				tell_object(me,"�Ѿ���ʼѵ����\n");
				return 1;
			}
			else tell_object(me,"�벻ҪƵ�������\n");
			return 1;
	}

	return 1;
}

void add_exp(object me,object env)
{
	int i,size,index,exp,yuanshen;
	object *users;

	//users = all_inventory(env);
	users = ({ me });
	size = sizeof(users);
	index = random(50);
	yuanshen = random(10);
	exp = random(50);
	for(i=0;i<size;i++)
	{
		if( !objectp(users[i]) || !userp(users[i]) || users[i]->is_npc()) continue;

		users[i]->add("potential",index);
		users[i]->add("combat_exp",exp);
		users[i]->add("jifeng",7);
       tell_object(users[i],ZJSIZE(22)GRN"ף����ʯ������Ч��ʹ�����ˣ�\n" +
        index + "Ǳ��\n" +		
        exp + "��Ϊֵ\n" +			
        7 + "��ȯ\n" +			

		        NOR);
//		if(users[i]->query("zhuanshen"))
//		{
//			users[i]->add("yuanshen/exp",yuanshen);
//		}
	}
	call_out("add_exp",10,me,env);
}

void add_skill(object me,object env)
{
	int i,size,index,skill_level;
	object *users;
	mapping skl;
	string *skillName,skill,skill_name;

	//users = all_inventory(env);
	users = ({ me });
	size = sizeof(users);

	index = 50;
	index = 50+random(index);
	for(i=0;i<size;i++)
	{
		if( !objectp(users[i]) || !userp(users[i]) || users[i]->is_npc()) continue;
		skl = users[i]->query_skills();
		if(!skl || !mapp(skl)) continue;
		skillName = ({"force","dodge","parry"});
		skill = skillName[random(sizeof(skillName))];
		if(!skill_level = users[i]->query_skill(skill, 1)) continue;

		users[i]->improve_skill(skill, index);

		//if(skill_name = SKILL_D(skill)->query_skill_name(skill_level))
		//	tell_object(users[i],sprintf(HIM"ף"HIY"��"HIW"��"RED"ʯ" HIC"������Ч�������%s�ġ�%s����һ���ƺ���Щ�ĵá�\n"NOR, to_chinese(skill),skill_name));
		//else tell_object(users[i],sprintf(HIM"ף"HIY"��"HIW"��"RED"ʯ" HIC"������Ч������ԡ�%s���ƺ���Щ�ĵá�\n"NOR,to_chinese(skill)));
	}
	call_out("add_skill",5,me,env);
}

