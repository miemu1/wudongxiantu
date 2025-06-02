// This program is a part of NT MudLIB

inherit  ROOM;
#define FUBEN_D  "/adm/npc/fubend"
void create()
{
        set("short",  "�θ�����");
        set("long",  @LONG
����˫����Ϊһ��������ȴ��ʧ�������˵ı�ɫ��լ֮ۡ�е���
�䳡���ݵ���Ϊ�������������οգ��ɷ����������ߵı������ϰ�
���ŵ���ǹ������ꪡ�����ʮ�˰���������Ҷ��ǲ��õú���������
����˫������ɳգ�ʱ�����������е�ǰ�����ޡ�����֮����ׯ�б�
���д衣
LONG);
        set("outdoors", "luoyang");
        set("region", "luoyang");
        set("no_fight", 1);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  "/d/luoyang/suishi2",
                "west"  :  __DIR__"dayuan",
        ]));
        set("objects",([
                __DIR__"npc/xu" : 1,
        ]));

        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob, room;

        if( me->query_temp("juxianzhuang_step") != 6 &&
            me->query_temp("juxianzhuang_step") != 13 )
                if( objectp(present("xu zhanglao", environment(me))) && dir == "west" )
                        return notify_fail("�쳤����ס��˵��������������ׯ��Ұ�����߿���\n");

        if( me->query_temp("juxianzhuang_step") == 13 && dir == "west" )
        {
                int valid;

                valid = FUBEN_D->valid_enter(me, "juxianzhuang");
                if( valid >=1 )
                {
                        room = get_object("/f/juxianzhuang/"+me->query("id")+"/zhengting");
                        ob = new("/maze/juxianzhuang/npc/azhu");
                        ob->move(room);
                        ob = new("/maze/juxianzhuang/npc/qiaofeng2");
                        ob->move(room);
                        FUBEN_D->enter_fuben(me, "juxianzhuang");
                        return -1;
                }
                else
                        return notify_fail("���޷��������ׯ������\n");
        }

        return ::valid_leave(me, dir);
}
