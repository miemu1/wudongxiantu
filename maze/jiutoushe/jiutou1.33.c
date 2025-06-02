#include <ansi.h>

inherit DEMONROOM;

void create()
{
        set("short", "��ͷ�����");
        set("long",@LONG
���Ǿ�ͷ�ߵ���أ���Χ���ǳ�ʪ�����ʪ�أ��ֲ�֮����
LONG);


	set("exits", ([
		"north"  : __DIR__"jiutou1.32",
		"out"    : __DIR__"haitan",
		
	]));
        	set("no_rideto", 1);         // ���ò������������ط�
       		set("no_flyto", 1);          // ���ò��ܴ������ط�����������
		set("n_time", 60);
		set("n_npc",1); 
		set("n_max_npc", 2);
		set("s_npc", "/clone/dream_npc/shenlongdao/snake/jiutoushe");

        setup();
}


// �ж�����Ƿ񸶷ѣ�δ�������ܽ���
void init()
{
	object me = this_player();
	int i;
	object *inv;
	
	if (! objectp(me))
	{
		me->move(__DIR__"haitan");
	}
	
	if (! playerp(me))return;
	
	if( !me->enter_jtshe_srv() )
	{
		tell_object(me, HIR "\n�Բ�����û�н����ͷ����ص���Ȩ�����ܽ��룡\n\n" NOR);
		me->move(__DIR__"haitan");
	}

	// �ѱ�����û�������
        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! playerp(inv[i])) continue;

                // ���˱�����û�
                inv[i]->move(__DIR__"haitan");                
        }	
	
	// �������
	return;
}
