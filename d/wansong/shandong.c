inherit ROOM;
#include <ansi.h>; 
void create()
{
        set("short", "����"); 
        set("long", @LONG
ɽ����խ����ϥ�ж�������һ��С�ģ��Ͳ��ⱻ���е�ʯ��ײ��
ͷ��Ѫ�������г�ʪ�������ȳ����ţ�һ����Ķ������������㲻
��ͷ��Ŀѣ�������쳣��
LONG );
        set("indoors", "wansong");
        set("type","mountain");
        set("exits",([
                "out":__DIR__"dongkou",
                "north":__DIR__"shandong1",
        ]) ); 
        set("coor/x",-610);
        set("coor/y",290);
        set("coor/z",80);
        setup();
        
} 
int valid_leave(object me, string dir)
{
        
        if(userp(me)&&!me->query_temp("fugui_liquan") && dir == "north")
        {
        message_vision( HIC "һ����Ķ�����������$N����ͷ��Ŀѣ,�����쳣��\n\n"NOR,me);
                //me->unconcious();
                return 0;
        } else
        {
                return 1;
        }
}  
