//ǩ���򿨹���

#include <ansi.h>
#include <localtime.h>
#define QIANDAO "/data/qiandao.o"

inherit NPC;

int do_daka();
int do_query_time();

void create()
{
	set_name("��Ϸ����Ա", ({ "qiandao npc" }));
	set("gender", "����");
	set("age", 20);
	set("per", 999);
	set("con", 999);
	set("int", 999);
	set("dex", 999);
	set("str", 999);
	set("qi", 9999999);
	set("max_qi", 9999999);
	set("jing", 9999999);
	set("neili", 9999999);
	set("max_neili",9999999);
	set("max_jingli",9999999);
	set("max_jing",9999999);
	set("combat_exp",100000000);
	set("no_suck", 1);
	set("title",HIG"��Ϸ����Ա"NOR);
	set("long","���Ǹ�����;��ҵ�ǩ����¼�Ĺ�����Ա��\n");
	set("no_kill",1);
	set("inquiry", ([
		"ÿ��ǩ��" : (: do_daka :),
		"��ѯǩ��" : (: do_query_time :),

	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}




int do_daka()
{
	object me, ob, env,ling;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, j, ok, day, month, size, data;
        int level;

	ob = this_object();
	me = this_player();

	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"ǩ��Ա˵���������������Ҵ�������\n"NOR);
		return 1;
	}

	data = me->query("dacard/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"ǩ��Ա˵����������Ѿ�ǩ�����ˣ����������ɡ�\n"NOR);
		return 1;
	}

	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//�·�
	{
		me->delete("dacard");
	}

	ob->set_temp("qiandao_time", time() + 2);//��÷�ʽ��ȡ��дӲ�̣�����������
	writeFile = QIANDAO;

	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");

		size = sizeof(meFilePach);
		ip = query_ip_number(me);

		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);

		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);

			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//��ͬ�ļ����ݱ�ʾ��IP�Ѿ�����ǩ��
			{
				ok =1;
				break;
			} else if (ip == ip2) {//ֻ��IP��ͬ����û��ǩ��
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}

	if (ok == 1)
	{
		tell_object(me, CYN"ǩ��Ա�����IP�����Ѿ�����ǩ�����ˡ�\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//��ʼ�����ļ�
		//��д�ļ�
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//ȥ��IP��ͬ������
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//��д��������
		}
	}
	if (ok !=1) {
		write_file(writeFile, sprintf("%s\n", item_max));//�¼�¼�����ļ�
	}
	if ( !objectp(env=environment(ob))
		|| !stringp(room=env->query("short")) )
	{
		::die();
		return 1;
	}

	i = 2000+random(2000);




		ling = new("/clone/shizhe/ling_tiaozhan");
		ling->move(me,3);
		me->set("tiaozhancishu", 0);
		me->set("kuangdao/menpiao", 2);
		me->delete("fubentd");
		me->delete("zhanling/s1");
		me->delete("zhanling/s2");
		me->delete("zhanling/s3");
		me->delete("zhanling/s4");
		me->delete("zhanling/s6");
		me->delete("zhanling/s8");
		me->add("yuanbao",200);

		me->add("zhanling/a5",100);




		me->set("dacard/time", time());
		tell_object(me, sprintf(CYN + "����һ����ս���� \n"NOR, i, i));
		tell_object(me, sprintf(CYN + "ħ�︱��������ˢ�� \n"NOR, i, i));
		tell_object(me, sprintf(CYN + "����100ս����Ϊֵ \n"NOR, i, i));
		tell_object(me, sprintf(CYN"����ǩ���ɹ���ף����Ϸ��죬����200Ԫ����\n"NOR));

		return 1;
}

int do_query_time()
{
	int time;
	mixed *localtime;
	object me = this_player();

	time = me->query("dacard/time");
	localtime = localtime(time);
	tell_object(me, sprintf(CYN"�㱾�µ�ĿǰΪֹ�ܹ�ǩ�� %d�Ρ�\n"NOR, me->query("dacard/cishu")) );
	tell_object(me, sprintf(CYN"%s���ϴ�ǩ��ʱ���ǣ�%d��%d��%d��%dʱ%d��%d�롣\n"NOR,
								me->query("name"), localtime[LT_YEAR], localtime[LT_MON] + 1,
								localtime[LT_MDAY], localtime[LT_HOUR], localtime[LT_MIN], localtime[LT_SEC] ));
	return 1;
}

void die()
{
	object me, ob;

	me = this_object();

	set("eff_qi", 10000);
	set("qi", 10000);
	set("eff_jing", 10000);
	set("jing", 10000);
	set("neili", 90000);
	set("max_jingli",10000);

	say( me->name() + CYN "˵�������ǲ����ģ������Ϊ�Ѿ�����¼�ڰ���\n"NOR);
	return;

}
