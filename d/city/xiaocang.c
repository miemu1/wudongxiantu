//qianting.c

#include <ansi.h>
inherit ROOM;
/*
mapping check_lvl = ([
	"1" : "��ͨģʽ",
	"2" : "����ģʽ",
	"3" : "����ģʽ",
]);*/
//��ѽ��븱������
int cs = 1;
void create()
{
        set("short", HIC"���ͻϮ"NOR);
        set("long", @LONG
����һ����ȫ�û��������ɵķ��ӣ����Ե�ǽ���ϲ������ͻ�ѣ��Ѵ���
�յ�ͨ�����ž��Ĵ����в�ʱ��������ž��ȼ���������������аڷ���һ��
̫ʦ�Σ����Է�����ʮ�������ӣ������ǽ�Ϲ���һ���ƽ�ĺ���(bian)����
����ȥ���ǽ��ͻϮ��ǰԺ�ˡ�
LONG
        );
	set("no_fight",1);
	set("item_desc",([
            "jjyy" : HIY"				 
            ��������������������������������������������������
            ��������������������������  ��������
            ����������                  ��������
            ��������    ���ͻϮ        ��������
            ����������                  ��������     
            ��������                    ��������
            ��������������������������������������������������"NOR"\n",
		]));
	set("action_list", ([
		HIG"���ͻϮ"NOR:"ask_job 1",
	]));	 
             
    
        setup();
}

void init()
{
    add_action("ask_job","ask_job");
}

int ask_quest()
{
	object me = this_player();
	string str;
	mixed *local,*last;
	int times;
	int ok =0,i;
	object *ob_list,room;
	int k;
	
	if (userp(me)) {
		if (me->query("fuben/jinbing")) {
		ob_list = children("/adm/daemons/fuben_jinbing");
		for(i=0; i<sizeof(ob_list); i++)  {
		if (ob_list[i]->query("id") == me->query("id")) {
		if (room = find_object(ob_list[i]->query("enter")))
		if (me->move(room))
			tell_object(me, HIR"ϵͳ��⵽���ϴεĸ�����δ����\n"NOR);
			return 1;
			}
		}
	}
		local = localtime(time());
		if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
				ok = cs;
		}
		last = localtime(me->query("fuben/jinbing/times"));
		times = me->query("fuben/jinbing/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing/mun",0);
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "�����Ѿ��������Ѿ����"+(2+ok)+"���ˣ����������ɡ�"NOR"\n");
			return 1;
		}
		/*
		str = ZJOBLONG"��ѡ��\n"ZJOBACTS2+ZJMENUF(2,3,9,30);
		str += "��ͨģʽ"+":ask_job 1"+ZJSEP;
		str += "����ģʽ"+":ask_job 2"+ZJSEP;
		str += "����ģʽ"+":ask_job 3";
*/
		tell_object(me, str+"\n");
	}
	return 1;
}

int ask_job(string arg)
{
	object obj, me=this_player();
	object fb_room, *ob;
	int i, ok=0;
	int times;
	mixed *local,*last;
	string data;

	if (!arg || (arg !="1" && arg !="2" && arg !="3")) {
		ask_quest();
		return 1;
	}
	if (to_int(arg) < 1 || to_int(arg)>3) {
		tell_object(me, "�����ʲô��"NOR"\n");
		return 1;
	}
	if (me->query_condition("killer")){
		tell_object(me, "����ɱ�˷�?��"NOR"\n");
		return 1;
	}
        if( me->query("eff_qi")<me->query("max_qi") )
               return notify_fail("����������ˣ����ʺϸ�����\n");

        if( me->query("eff_jing")<me->query("max_jing") )
               return notify_fail("����������ˣ����ʺϸ�����\n");
               	
	ob=deep_inventory(me);
	for (i=0;i<sizeof(ob);i++) {
		if (userp(ob[i])) {
			tell_object(me, "��֧����ӣ�\n");
			return 1;
		}
	}

	me->delete_temp("ask_no");

	local = localtime(time());

	//����ṩһ�ν������
	if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
			ok = cs;
	}
		last = localtime(me->query("fuben/jinbing/times"));
		times = me->query("fuben/jinbing/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing/mun",0);
			/*
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "�����Ѿ��������Ѿ����"+(2+ok)+"���ˣ����������ɡ�"NOR"\n");
			return 1;
	}*/
	data = (to_int(local[4])+1)+"-"+local[3];
	if (me->query("fuben/jinbing/mun") <= cs)
	{
		me->set("fuben/jinbing/times",time());
		me->add("fuben/jinbing/mun", 1);
		me->add("fuben/jinbing/"+data, 1);
		me->move("/fuben/jinbing/enter");
		fb_room = new("/adm/daemons/fuben_jinbing");//��
		fb_room->init(me);
		fb_room->set("id", me->query("id"));
		tell_object(me, HIR"�����ڽ��н��ͻϮѵ������"NOR"\n");
	} else 
		tell_object(me, "��������������Ѿ�û����\n");
	return 1;
}