//huyuan.c

inherit "/inherit/char/huyuan.c";

void create()
{
    if(!restore())
    {
        set("long", "������؃Ʈ�ݳ������ľ��ɷ���ǡ�\n");
        set("gender", "����");
        set("attitude", "friend");
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("age", 30);
        set("per", 40);
        set("set_skill/level", 900);
        set("set_skill/owner", "HOUSE_D");
        set("owner", "OWNER");
        set("owner_name", "ĳ��");
    }
    if(!query("modify/name"))
        set_name(query("owner_name") + "�Ļ�Ժ", ({ "hu yuan", "huyuan" }));
    else
        set_name(query("modify/name"), ({ "hu yuan", "huyuan" }));

    setup();
    add_all_settings();
}
