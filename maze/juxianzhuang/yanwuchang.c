// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "���䳡");
        set("long",  @LONG
����˫����Ϊһ��������ȴ��ʧ�������˵ı�ɫ��լ֮ۡ�е����䳡
���ݵ���Ϊ�������������οգ��ɷ����������ߵı������ϰڷ���
����ǹ������ꪡ�����ʮ�˰���������Ҷ��ǲ��õú�������������
˫������ɳգ�ʱ�����������е�ǰ�����ޡ�����֮����ׯ�б�����
�衣
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"neitang",
                "east"  :  __DIR__"huayuan",
                "south" :  __DIR__"changlang4",
                "north" :  __DIR__"changlang3",
        ]));
        /*
        set("objects",([
                __DIR__"npc/haojie" : 1,
                __DIR__"npc/sengren" : 1,
                __DIR__"npc/qigai"  : 1,
        ]));
        */
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
