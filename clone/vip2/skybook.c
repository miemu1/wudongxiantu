// change by edward
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"ʮ������"NOR,({"skybook","book"}));
    set("long","������ӹ�����µ��飬��˵�������ż�������ܣ����߶�ʧ��\n"ZJURL("cmds:study book11")+ZJSIZE(20)+"����"NOR"��\n");
    set("unit","��");
    set("value",100);
		set("base_value", 10);

    setup();
}

void init()
{
       add_action("do_study", "study");
}
int do_study(string arg)
{
	string dest;

    string desc,name,file;
	mapping exit;

    object me=this_player();
    file=WABAO_D->query("file");

    desc=WABAO_D->query("desc");
	name=WABAO_D->query("short");
    if (arg=="skybook11"||arg=="book11")
        {
        if (me->query("jing")<20) return notify_fail("��̫���ˣ���Ъ����ɡ�\n");
        message_vision(HIC"$N̯��"+HIW"ʮ������"+HIC"�������ж���\n"NOR,me);
        if (stringp(desc))
		{
				if(wizardp(me))
				{
            tell_object(me,"�����Ȼ�ֳ�һ��������\n��"HIY+name+NOR"�� \n"HIG+desc+"\n"HIC"·����"+file+"\n"+ZJURL("cmds:goto "+file)+"˲���ƶ�"+NOR""+"\n"NOR);
 //           tell_object(me,"ZJURL("cmds:goto "+file)+"�ɹ�ȥ"+NOR"��);

//				CHANNEL_D->do_channel( this_object(), "sys", "���������ˡ�"+ZJURL("cmds:goto "+(file))+"�ɹ�ȥ"+NOR"��");

				}else
				{
            tell_object(me,"�����Ȼ�ֳ�һ��������\n��"HIY+name+NOR"�� \n"HIG+desc+"\n"NOR);

				}
        return 1;
		}
        }
    else return 0;
}
