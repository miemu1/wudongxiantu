
#include <ansi.h>

inherit NPC;

void clean_me()
{
	return;
}

mapping att_lv = ([
	"��ͨ[1�ڱ���]":1,
	"ǿ��[5�ڱ���]":5,
	"�ػ�[25�ڱ���]":25,
]);

string *ob_list = ({
		"/clone/gift/fudai",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/lingzhi",
	"/clone/vip/tianxiang",
	"/clone/vip/book_tianfu",
	"/clone/vip/book_wuliang",
	"/clone/vip/jinpiao",
	"/clone/gift/fudai",
	"/clone/vip/dan_chongmai1",
	"/clone/vip/dan_chongmai2",
	"/clone/vip/dan_chongmai1",
	"/clone/vip/dan_chongmai2",
	"/clone/vip/dan_chongmai3",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/lingzhi",
	"/clone/vip/tianxiang",
	"/clone/gift/fudai",
	"/clone/vip/book_tianfu",
	"/clone/vip/book_wuliang",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/putao1",
	"/clone/gift/fudai",
	"/clone/gift/cagate",
	"/clone/gift/ccrystal",
	"/clone/gift/cdiamond",
	"/clone/gift/cjade",
	"/clone/vip2/xuanling",
});

string *ob_list1 = ({
		"/clone/vip/ling_wolong",
	"/clone/gift/fudai",
	"/clone/vip/dan_int",
	"/clone/vip/dan_str",
	"/clone/vip/dan_dex",
	"/clone/gift/fudai",
	"/clone/vip/ling_wolong",
	"/clone/vip/dan_con",
	"/clone/vip/putao1",
	"/clone/vip/dan_int",
	"/clone/vip/tiancs",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_str",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_dex",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_con",
	"/clone/vip/dan_chongmai4",
	"/clone/gift/agate",
	"/clone/gift/crystal",
	"/clone/gift/diamond",
	"/clone/gift/jade",
	"/clone/vip/jiuzhuan",
	"/clone/vip/tiancs",
	"/clone/vip/butian",
	"/clone/vip/ling_wolong",
	"/clone/gift/fudai",
	"/clone/vip/dan_int",
	"/clone/vip/dan_str",
	"/clone/vip/dan_dex",
	"/clone/gift/fudai",
	"/clone/vip/ling_wolong",
	"/clone/vip/dan_con",
	"/clone/vip/putao1",
	"/clone/vip/dan_int",
	"/clone/vip/tiancs",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_str",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_dex",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_con",
	"/clone/vip/dan_chongmai4",
	"/clone/gift/agate",
	"/clone/gift/crystal",
	"/clone/gift/diamond",
	"/clone/gift/jade",
	"/clone/vip/jiuzhuan",
	"/clone/vip/tiancs",
	"/clone/vip/butian",
	"/clone/tianji1/qilin",
	"/clone/tianji1/huanyutianjing",
});

void create()
{
	set_name(HIR"����"NOR, ({ "nian shou" }) );
	set_weight(99999999);
	set("long", "ͷ�����ǣ��������ݣ�Ŀ¶�׹⣬�����쳣��������Ӻ��ף�ÿ����Ϧ�����ϰ�����ʳ�����˺�������\n");
	set("unit", "ֻ");
	set("no_get", 1);
	set("qi",10000);
	set("acts_list",([
		"����":"duobao",
	]));
	set("max_qi",10000);
	setup();
}

void do_back()
{
	CHANNEL_D->do_channel(this_object(), "rumor","��˵�����������˼���ŰһȦ��֪���٣�����Ӣ�ۺ����������޵��´���Ϯ��" NOR);
	destruct(this_object());
}

void get_damage(object me, int damage, int type)
{
	object ob,obj;

	ob = this_object();

	me->add("potential",damage*60);
	tell_object(me,"ֻ������ž��һ�����죬����������"+damage+"���˺������"+damage*60+"��Ǳ�ܡ�\n");
	if((damage > random(1600)) || (random(90)==50))
	{
		obj = new("/clone/vip/jiuzhuan");
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�ش����޻��"+obj->short()+"��");
		log_ufile(me,"qilin","�ش�("+damage+")���޻��"+obj->short()+"��\n");
		tell_object(me,"���ش����޻��"+obj->short()+"��\n");
		obj->move(me);
	}
	if((damage > random(300)) || (random(20)==10))
	{
		obj = new(ob_list1[random(sizeof(ob_list1))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�ش����޻��"+obj->short()+"��");
		log_ufile(me,"qilin","�ش�("+damage+")���޻��"+obj->short()+"��\n");
		tell_object(me,"���ش����޻��"+obj->short()+"��\n");
		obj->move(me);
	}
	if((damage > random(100)) || (random(6)==1))
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�ش����޻��"+obj->short()+"��");
		log_ufile(me,"qilin","�ش�("+damage+")���޻��"+obj->short()+"��\n");
		tell_object(me,"���ش����޻��"+obj->short()+"��\n");
		obj->move(me);
	}
	ob->add("qi",-damage);
	message("vision", ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n", 
				filter_array(all_inventory(environment(ob)), (: interactive($1) :)) );
	if(ob->query("qi")<=0)
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�������������һ�����"+obj->short()+"��");
		log_ufile(me,"qilin","�������������һ��("+damage+")���"+obj->short()+"��\n");
		tell_object(me,"��������������һ�����"+obj->short()+"��\n");
		obj = new("/clone/gift/fudai");
		obj->move(me);
		tell_object(me,"��������������һ�����"+obj->short()+"��\n");
		obj->move(me);
		if(damage > random(500) || random(5)==1)
		{
			obj = new(ob_list1[random(sizeof(ob_list1))]);
			CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�������������һ�����"+obj->short()+"��");
			log_ufile(me,"qilin","�������������һ�����"+obj->short()+"��\n");
			tell_object(me,"��������������һ�����"+obj->short()+"��\n");
			obj->move(me);
		}
		if(damage > random(220) || random(5)==2)
		{
			obj = new("/clone/vip/vip2/dan_jiuzhuan");
			CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"�������������һ�����"+obj->short()+"��");
			log_ufile(me,"qilin","�������������һ�����"+obj->short()+"��\n");
			tell_object(me,"��������������һ�����"+obj->short()+"��\n");
			obj->move(me);
		}
		destruct(ob);
	}
}

void init()
{
	object ob,me;

	me = this_player();
	ob = this_object();
	if(playerp(me))
	{
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		add_action("do_duobao","duobao");
	}
}

int do_duobao(string arg)
{
	object me,ob;
	string *lvs,str;
	int lv;

	me = this_player();

	if(me->is_busy())
		return notify_fail("������æ���أ�\n");

	if(!objectp(ob=present("bao zhu",me)))
		return notify_fail("������û�б����޷������������Ч�˺���\n");

	if(!arg)
	{
		str = ZJOBLONG"�����˴�˵֮�ֻ���ñ�����ܶ������һ�����˺���Ѱ�����Կ����벽"ZJBR"��ѡ�񹥻�ǿ�ȣ�\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "��ͨ[1�ڱ���]:duobao ��ͨ[1�ڱ���]"ZJSEP;
		str += "ǿ��[5�ڱ���]:duobao ǿ��[5�ڱ���]"ZJSEP;
		str += "�ػ�[25�ڱ���]:duobao �ػ�[25�ڱ���]";
		tell_object(me,str + "\n");
		return 1;
	}

	if(!att_lv[arg])
		return notify_fail("ѡ�����������ѡ��\n");

	if(ob->query_amount() < att_lv[arg])
		return notify_fail("������û����ô�౬��\n");
	ob->add_amount(-att_lv[arg]);
	tell_object(me,HIG"���ȼһЩ������������ȥ��"NOR"\n");
	me->start_busy(1);
	get_damage(me,att_lv[arg]*10,2);
	return 1;
}
