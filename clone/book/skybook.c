// change by edward
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"ʮ������"NOR,({"skybook","book"}));
    set("long","������ӹ�����µ��飬��˵�������ż�������ܡ�\n"
		ZJURL("cmds:study skybook")+ZJSIZE(20)+HIC"��һ��"NOR"\n" );
    set("unit","��");
    set("value",1400);
    setup();
}

void init()
{
       add_action("do_study", "study");
       add_action("do_study", "du");
}
int do_study(string arg)
{
    string desc,name;
    object me=this_player();
    desc=WABAO_D->query("desc");
	name=WABAO_D->query("short");
    if (arg=="skybook"||arg=="book")
        {
        if (me->query("jing")<20) return notify_fail("��̫���ˣ���Ъ����ɡ�\n");
        message_vision(HIC"$N̯��"+HIW"ʮ������"+HIC"�������ж���\n"NOR,me);
        if (stringp(desc))
            tell_object(me,"�����Ȼ�ֳ�һ��������\n��"HIY+name+NOR"�� \n"HIG+desc+"\n"NOR);
        return 1;
        }
    else return 0;
}
