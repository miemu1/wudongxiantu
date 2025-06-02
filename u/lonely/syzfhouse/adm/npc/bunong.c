// /adm/npc/bunong.c ���סլ�����ˣ���ٯ
// By Alf, Last Update 2003.0730
// Modify By Alf@Syzf, Last Update 2005.0402
// ����ԭַ�Ľ���������޹���

#include <ansi.h>
#include "house_picture.h"

inherit NPC;

#define BASE_DIR    "/clone/house/base/"
#define VIP_VALUE   1000
#define VIP_LIMIT   28
#define VIP_ORIGIN  12

public int show_type(object me);                        //�����б�
public int show_base(object me);                        //�ؿ��б�
private int choice_type(string arg);                    //ѡ������
private int choice_base(string arg);                    //ѡ���ؿ�
private int build_house(string arg);                    //���췿��
private int do_rebuild(string arg);                     //ԭַ�Ľ�
private int do_cession(string arg);                     //����ת��
private int do_dismantle(string arg);                   //���ݲ��
public void confirm_type(string yn);                    //ȷ��ѡ��
public void confirm_base(string yn);                    //ȷ��ѡ��
public void confirm_build(string yn);                   //ȷ�Ͻ���
public void confirm_rebuild(string yn);                 //ȷ�ϸĽ�
public void confirm_cession(string yn);                 //ȷ��ת��
public void confirm_dismantle(string yn);               //ȷ�ϲ��
public void confirm_addvips(string yn);                 //ȷ������
public void check_password(string passwd, object me);   //������
public void add_all_inquiry();                          //��ѯ����
private int ask_cmds();                                 //ָ�����
private int house_picture_user();                       //��ʾͼ��
private int house_picture_bang();                       //��ʾͼ��
private int house_picture_xian();                       //��ʾͼ��
private void reset_all_static();                        //��������
private int add_vip_count(string arg);                  //�������

static int the_value = 0;
static int max_laodu = 0;
static string the_name = "";
static string the_type = "";
static string the_base = "";
static mapping npc_data = ([]);

void create()
{
    set_name("��ٯ", ({ "bu nong", "bu", "nong" }));
    set("nickname", HIC"��������"NOR);
    set("title", HIM"��������"NOR);
    set("channel_id", "��������");
    set("gender", "Ů��");
    set("shen", 0);
    set("age", 20);
    set("per", 40);
    set("no_get", 1);
    set("wiz_tester", 1);
    set("combat_exp", 10000000);
    set("attitude", "friendly");
    set("long", "\n����һ�������Ů���ӣ�ȴһ�ֲ����ˡ�"HIY +
                MUD_NAME + NOR"�������з��ݽ������ˡ�\n");

    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_all_inquiry();
}

void init()
{
    add_action("show_type", "showtype");              //�����б�
    add_action("choice_type", "choosetype");          //ѡ������
    add_action("show_base", "showbase");              //�ؿ��б�
    add_action("choice_base", "choosebase");          //ѡ���ؿ�
    add_action("build_house", "buildhouse");          //���췿��
    add_action("do_cession", "cession");              //����ת��
    add_action("do_dismantle", "dismantle");          //���ݲ��
    add_action("do_rebuild", "rebuild");              //ԭ�ظĽ�
    add_action("add_vip_count", "addvips");           //�������
}

public void add_all_inquiry()
{
    int i;
    string type;
    mapping *all_house, all_inquiry;

    all_inquiry = ([]);
    all_house   = HOUSE_D->query_house_type();
    for(i = 0; i < sizeof(all_house); i++)
    {
        if(all_house[i]["type"] == "user")
        {
            type = "���סլ";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_user :)]);
            all_inquiry += ([ type : (: house_picture_user :)]);
        }
        if(all_house[i]["type"] == "bang")
        {
            type = "���פ��";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_bang :)]);
            all_inquiry += ([ type : (: house_picture_bang :)]);
        }
        if(all_house[i]["type"] == "xian")
        {
            type = "ɢ�ɾ���";
            all_inquiry += ([ all_house[i]["name"] : (: house_picture_xian :)]);
            all_inquiry += ([ type : (: house_picture_xian :)]);
        }
    }

    all_inquiry += ([
        "ָ��" : (: ask_cmds :),
        "����" : (: ask_cmds :),
        "cmds" : (: ask_cmds :),
        "help" : (: ask_cmds :),
    ]);

    this_object()->set("inquiry", all_inquiry);
}

private int ask_cmds()
{
    object me, ob;
    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, HIW@TEXT

        �����б�showtype
        �ؿ��б�showbase
        ѡ�����ͣ�choosetype <��լ����>
        ѡ���ؿ飺choosebase <�ؿ�����>
        ���췿�ݣ�buildhouse <��լ����> on <�ؿ�����>
        ������ޣ�   addvips <��լ����>
        ԭַ�Ľ���   rebuild <ԭ����լ����>     ������֤ԭ����լ���룩
        ����ת�ã�   cession <��լ����> to <�Է�ID> ������֤��լ���룩
        ���ݲ���� dismantle <���ID> <��լ����>    ������֤��լ���룩

TEXT NOR);
    return 1;
}

public int show_type(object me)
{
    object ob;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "˵�˼��仰��\n", environment(me), ({ me, ob }));
    HOUSE_D->show_type(me);
    return 1;
}

private int choice_type(string arg)
{
    int i, value;
    object me, ob;
    mapping *house_type;
    string name, type;

    me = this_player();
    ob = this_object();

    if(!arg || arg == "")
        return notify_fail(HIW "ָ���ʽ��choosetype <��լ����>\n" NOR);

    house_type = HOUSE_D->query_house_type();
    for(i = 0; i < sizeof(house_type); i++)
    {
        if(arg != house_type[i]["name"])
            continue;
        type  = house_type[i]["type"];
        name  = house_type[i]["name"];
        value = house_type[i]["value"];
    }

    if(!type)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ����Ŀǰ���ޡ�"
                        HIW + arg + NOR YEL"�������죬����ϸ�鿴"
                            "��լ����(showtype)��\n" NOR);
        return 1;
    }

    if(type == "xian")
    {
        if(!wizardp(me) && wizhood(me) != "(immortal)")
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ�������»�û��λ��"
                                "�Ͻ��ɰ࣬���ܽ��졸" HIW + name + NOR
                            YEL "��������լ��\n" NOR);
            return 1;
        }
    }

    if(type == "bang")
    {
        if(!wizardp(me) && me->query("bang/class") != 1)
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ����������δ�ٵ�"
                                "�������������ܽ��졸" HIW + name + NOR
                            YEL "��������լ��\n" NOR);
            return 1;
        }

        if(me->query("bank/gold") < value)
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ�������µĴ���"
                                "֧����"HIW + name + NOR YEL"��������լ"
                                "����ۣ�ȥ�湻��Ǯ�����ɡ�\n" NOR);
            return 1;
        }

        if(!wizardp(me) && wizhood(me) != "(player)")
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ��������ҵ����̥"
                                "���ɣ�������׷����Щ����֮���ˡ�\n" NOR);
            return 1;
        }
    }

    if(type == "user")
    {
        if(me->query("house/user")
            && !me->query_temp("building_house/rebuild"))   //���ǸĽ�
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ���������Ѿ�ӵ��һ��"
                                "���סլ�ˣ������ٶ��졣\n" NOR);
            tell_object(me, YEL + ob->name(1) + "��Ц�����������ԭַ�Ľ���"
                            "��ʹ��" HIW " rebuild " NOR YEL "ָ�\n" NOR);
            return 1;
        }

        if(me->query("bank/gold") < value)
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ�������µĴ���"
                                "֧����"HIW + name + NOR YEL"��������լ"
                                "����ۣ�ȥ�湻��Ǯ�����ɡ�\n" NOR);
            return 1;
        }

        if(!wizardp(me) && wizhood(me) != "(player)")
        {
            message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, YEL + ob->name(1) + "ҡͷ��������ҵ����̥"
                                "���ɣ�������׷�����ෲ��֮���ˡ�\n" NOR);
            return 1;
        }
    }
    message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, HIC "\n" + ob->name(1) + "��ͷ����" NOR);
    HOUSE_D->choice_type(arg, me);
    tell_object(me, HIC "��ȷ����(y/n)��\n" NOR);
	input_to("confirm_type", me);
    return 1;
}

public void confirm_type(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("building_house");
        message_vision(YEL "$N�����룬��$nҡͷ�����һ����ٿ����ɡ�\n" NOR, me, ob);
        return;
    }
    else
        message_vision(HIC "$N�����룬��$n��ͷ�����Ҿ�ѡ����һ�֡�\n" NOR, me, ob);
    return;
}

public int show_base(object me)
{
    object ob;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "˵�˼��仰��\n", environment(me), ({ me, ob }));
    HOUSE_D->show_base(me);
    return 1;
}

private int choice_base(string arg)
{
    int i;
    object me, ob, room;
    string name, type;
    mapping base;

    me = this_player();
    ob = this_object();
    base = HOUSE_D->query_house_base();

    if(!arg || arg == "")
        return notify_fail(HIW "ָ���ʽ��choosebase <�ؿ�����>\n" NOR);

    if(!me->query_temp("building_house"))
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ��������ѡ�������Ҫ"
                            "�������լ����(choosetype)��\n" NOR);
        return 1;
    }

    name = me->query_temp("building_house/name");
    type = me->query_temp("building_house/type");
    for(i = 0; i < sizeof(base); i++)
    {
        if(base[i]["name"] == arg)
        {
            room = get_object(BASE_DIR + base[i]["file"]);
            if(base[i]["type"] != type)
            {
                message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, YEL + ob->name(1) + "ҡͷ������" HIW + arg +
                            NOR YEL "�����ʺϽ�������ѡ��ġ�" HIC + name +
                            NOR YEL "��������ѡһ�����ʵĵؿ顣\n" NOR);
                return 1;
            }
            if(room->query("house_build") >= room->query("max_build"))
            {
                message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, YEL + ob->name(1) + "ҡͷ������" HIW + arg +
                            NOR YEL "�������Ѿ������㹻�����լ��������ѡһ��"
                                    "�п�λ�ĵؿ�ɡ�\n" NOR);
                return 1;
            }
            message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                              "����С��˵�˼��仰��\n", environment(me),
                                                        ({ me, ob }));
            tell_object(me, HIC "\n" + ob->name(1) + "��ͷ����" NOR);
            HOUSE_D->choice_base(arg, me);
            tell_object(me, HIC "��ȷ����(y/n)��\n" NOR);
	        input_to("confirm_base", me);
            return 1;
        }
    }

    message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + ob->name(1) + "ҡͷ����û�С�" HIW + arg +
                NOR YEL"������ؿ飬����ϸ�鿴�ؿ��б�(showbase)��\n" NOR);
    return 1;
}

public void confirm_base(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("building_house/base");
        message_vision(YEL "$N�����룬��$nҡͷ�����һ����ٿ����ɡ�\n" NOR, me, ob);
        return;
    }
    else
        message_vision(HIC "$N�����룬��$n��ͷ�����Ҿ�ѡ����һ����\n" NOR, me, ob);
    return;
}

private int build_house(string arg)
{
    int value;
    object me, ob;
    mapping base;
    string name, type, target;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s on %s", type, target) != 2)
        return notify_fail(HIW "ָ���ʽ��buildhouse <��լ����> "
                               "on <�ؿ�����>\n" NOR);

    name = me->query_temp("building_house/name");
    base = me->query_temp("building_house/base");
    if(!name)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                         "����С��˵�˼��仰��\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�������»�û��ѡ���"
                            "Ҫ�������լ���͡�\n" NOR);
        return 1;
    }
    if(!base)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                         "����С��˵�˼��仰��\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�������»�û��ѡ���"
                            "Ҫ������լ�ĵؿ顣\n" NOR);
        return 1;
    }
    if(type != name)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                         "����С��˵�˼��仰��\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�������¸ղź���ѡ��"
                            "�Ĳ���������լ���Ͱɣ�\n" NOR);
        return 1;
    }
    if(target != base["name"])
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                         "����С��˵�˼��仰��\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�������¸ղź���ѡ��"
                            "�Ĳ�������ؿ�ɣ�\n" NOR);
        return 1;
    }

    value = me->query_temp("building_house/val_t"); //���ݵ����
    if(!me->query_temp("rebuild_house"))
        value += base["value"];                     //�ǸĽ����լ���ؼ�
    me->set_temp("building_house/value", value);    //��լ�����
    if(me->query("bank/gold") < value)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                         "����С��˵�˼��仰��\n", environment(me),
                                                   ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�������µĴ���"
                            "֧����լ����۹��� "WHT + value + YEL
                            " ���ƽ�ȥ�湻��Ǯ�����ɡ�\n" NOR);
        return 1;
    }

    message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, HIC + ob->name(1) + "��ͷ���������ڡ�"
                    HIW + target + HIC "������һ�ס�"
                    HIW + name + HIC"���������� "
                    HIY + value + " ���ƽ�"
                    HIC "��ȷ����(y/n)��\n" NOR);
	input_to("confirm_build", me);
    return 1;
}

public void confirm_build(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N�����룬��$nҡͷ���������ٿ���һ�°ɡ�\n" NOR, me, ob);
        return;
    }
    message_vision(HIC "$N�����룬��$n��ͷ�����������ɣ��Ҿ����ˡ�\n" NOR, me, ob);
    me->set_temp("building_house/zhuan", "HOUSE_D");    //������լ��Դ��־
    me->set_temp("building_house/build", "build");      //���ӽ����־�Կ�Ǯ

    if(me->query_temp("rebuild_house")) //ԭַ�Ľ�ǰ�Ȳ��������լ
    {
        HOUSE_D->do_dismantle(me, me->query_temp("building_house/rebuild"));
    }

    HOUSE_D->build_house(me);

    if(me->query_temp("rebuild_house"))
    {
        me->delete_temp("rebuild_house");   //���ɾ������������
        reset_all_static();
    }

    return;
}

private int do_rebuild(string arg)
{
    int i, vips;
    object me, ob, room, huyuan;
    string name, type, tag, *key, msg;
    mapping build, house, base, old_vip;

    if(!arg || arg == "")
        return notify_fail(HIW "ָ���ʽ��rebuild <ԭ����լ����>\n" NOR);

    me = this_player();
    ob = this_object();
    build = me->query("house/build");
    if(!build)
    {
        tell_object(me, YEL "���н����������լ��\n" NOR);
        return 1;
    }
    if(mapp(build) && sizeof(build) > 0)
    {
        key = keys(build);
        for(i = 0; i < sizeof(key); i++)
        {
            if(build[key[i]] == arg)
            {
                house = me->query("house/" + key[i]);
                the_type = key[i];  //��¼��լ����
                the_name = arg;     //��¼��լ����
                break;
            }
        }
        if(!house)
        {
            tell_object(me, YEL "���н����������լ��\n" NOR);
            return 1;
        }
    }
    if(mapp(house) && sizeof(house) > 0)
    {
        key = keys(house);
        for(i = 0; i < sizeof(key); i++)
        {
            if(key[i] == "base")
            {
                base = house[key[i]];
                me->set_temp("building_house/base", base);
                the_base = base["name"];   //��¼լ������
                the_value = house["value"]; //��¼��լ��ֵ
                room = get_object(house["entry"]);
                max_laodu = (int)room->query("max_laodu");   //�����ζ�
                huyuan = get_object(room->query("huyuan"));    //���һ�Ժ
                huyuan->restore();
//------------------------------------------------------------------------------------
                npc_data["name"]   = huyuan->query("name");     //��Ժ����
                npc_data["long"]   = huyuan->query("long");     //��Ժ����
                npc_data["gender"] = huyuan->query("gender");   //��Ժ�Ա�

                if(stringp(huyuan->query("nickname")))          //��Ժ���
                    npc_data["nickname"] = huyuan->query("nickname");
                if(stringp(huyuan->query("title")))             //��Ժͷ��
                    npc_data["title"] = huyuan->query("title");

                npc_data["level"] = huyuan->query("set_skill/level");   //��Ժ�ȼ�
                npc_data["skill"] = huyuan->query("generation_skill/code"); //��Ժ����

                vips = huyuan->query("vip_limit");
                if(vips <= 0)
                    vips = VIP_ORIGIN;
                npc_data["vip_limit"] = vips;       //�������

                old_vip = huyuan->query("vip");
                if(mapp(old_vip) && sizeof(old_vip) > 0)
                    npc_data["vip"] = old_vip;
//------------------------------------------------------------------------------------
                me->set_temp("building_house/rebuild", the_type);   //���ϿɸĽ����
                break;
            }
        }
    }

    if(!me->query_temp("building_house/name"))
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�����Ľ�ǰ����ѡ�������Ҫ"
                            "�������լ����(choosetype)��\n" NOR);
        return 1;
    }

    name = me->query_temp("building_house/name");
    type = me->query_temp("building_house/type");
    room = get_object(base["file"]);
    if(name == arg)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                          "����С��˵�˼��仰��\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "%sҡͷ�������Ѿ������ڡ�" HIW "%s" NOR
                                YEL "���ϵ���լ�����ǡ�" HIC "%s" NOR
                                YEL "�����ַ�����\n" NOR,
                                ob->name(1), base["name"], name));
        return 1;
    }
    if(room->query("can_build") != type)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                          "����С��˵�˼��仰��\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "%sҡͷ������ԭ�е�լ����" HIW "%s" NOR
                                YEL "�����ʺϽ�����ѡ��Ľ��ġ�" HIC "%s" NOR
                                YEL "��������ѡ���ʵķ��͡�\n" NOR,
                                    ob->name(1), base["name"], name));
        return 1;
    }
/*
//-------------------------------------------------------------------------------
    tell_object(me, sprintf("\n\n\t��լ���ƣ�%s\n"
                            "\t��լ���ͣ�%s\n"
                            "\t��լ�ػ���%s\n"
                            "\t��լ��ֵ��%d\n"
                            "\t�����ζȣ�%d\n",
                            the_name, the_type, the_base, the_value, max_laodu));
    msg = "";
    key = sort_array(keys(npc_data), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(stringp(npc_data[key[i]]))
            msg += sprintf("\t%s : %s\n", key[i], npc_data[key[i]]);
        if(intp(npc_data[key[i]]))
            msg += sprintf("\t%s : %d\n", key[i], npc_data[key[i]]);
        if(mapp(npc_data[key[i]]))
            msg += sprintf("\t%s : %d\n", key[i], sizeof(npc_data[key[i]]));
    }
    msg += "\n";
    tell_object(me, msg);
//-------------------------------------------------------------------------------
*/
    message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me),
                                                ({ me, ob }));
    tell_object(me, sprintf(HIC "\n%s��ͷ���������Ľ��ڡ�" HIW "%s"
                            HIC "������ӵ�еġ�" HIY "%s"
                            HIC "����ȷ����(y/n)��\n" NOR,
                                ob->name(1), base["name"], the_name));

    input_to("confirm_rebuild", me);
    return 1;
}

public void confirm_rebuild(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        reset_all_static();
        message_vision(YEL "$N�����룬��$nҡͷ���������ٿ���һ�°ɡ�\n" NOR, me, ob);
        return;
    }
    message_vision(HIC "$N�����룬��$n��ͷ�����������ɣ��Ҿ����ˡ�\n" NOR, me, ob);
//--------------------------------------------------------------------
    me->set_temp("rebuild_house/the_base", the_base);   //��¼��լ�ػ�
    me->set_temp("rebuild_house/the_name", the_name);   //��¼��լ����
    me->set_temp("rebuild_house/the_type", the_type);   //��¼��լ����
    me->set_temp("rebuild_house/the_value", the_value); //��¼��լ��ֵ
    me->set_temp("rebuild_house/max_laodu", max_laodu); //��¼�����ζ�
    me->set_temp("rebuild_house/npc_data", npc_data);   //��¼��Ժ����
//--------------------------------------------------------------------
    tell_object(me, HIW "������ԭ����լ���룺" NOR);
    input_to("check_password", 1, me);
    return;
}

private int do_cession(string arg)
{
    int i;
    object me, who, ob;
    string target, name, *key;
    mapping build;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s to %s", name, target) != 2)
        return notify_fail(HIW "ָ���ʽ��cession <��լ����> "
                               "to <��ת����ID>\n" NOR);

    build = me->query("house/build");
    if(sizeof(build) == 0)
        return notify_fail(YEL "���н������լ��\n" NOR);

    key = sort_array(keys(build), 1);
    if(target == me->query("id"))
        return notify_fail(YEL "ת�ø��Լ�������˰ɡ�\n" NOR);

    if(!objectp(who = present(target, environment(me)))
        || !userp(who)
        || !interactive(who)
        || !who->is_livings())
            return notify_fail(YEL "����û������ˡ�\n" NOR);

    for(i = 0; i < sizeof(key); i++)
    {
        if(build[key[i]] != name)
            continue;
        if(build[key[i]] == name)
        {
            if(key[i] == "bang" || key[i] == "xian")
            {
                if(!wizardp(me))
                {
                    message("vision", ob->name(1) + "ҡ��ҡͷ����"
                                    + me->name() + "����С��˵�˼��仰��\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + ob->name(1) + "ҡͷ������"
                                    HIW + name + NOR YEL"��������լ"
                                        "�ǲ�����ת�õġ�\n" NOR);
                    return 1;
                }

                message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "��ͷ��������ӵ�еġ�"
                                HIY + name + HIC "������ת�ø���"
                                HIW + who->name() +
                                HIC "����ȷ����(y/n)��\n" NOR);
                me->set_temp("cession_house/type", key[i]);
                me->set_temp("cession_house/name", who->query("id"));
                input_to("confirm_cession", me);
                return 1;
            }

            if(key[i] == "user")
            {
                if(!wizardp(me) && wizhood(who) != "(player)")
                {
                    message("vision", ob->name(1) + "ҡ��ҡͷ����"
                                    + me->name() + "����С��˵�˼��仰��\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + "\n" + ob->name(1) + "ҡͷ����"
                                        + who->name() + "�Ѿ�������Ҫ"
                                        "��Щ���������ˡ�\n" NOR);
                    return 1;
                }
                message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "��ͷ��������ӵ�еġ�"
                                HIY + name + HIC "������ת�ø���"
                                HIW + who->name() +
                                HIC "����ȷ����(y/n)��\n" NOR);
                me->set_temp("cession_house/type", key[i]);
                me->set_temp("cession_house/name", who->query("id"));
                input_to("confirm_cession", me);
                return 1;
            }
        }
    }

    message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + "\n" + ob->name(1) + "ҡͷ�������н������"
                    HIW + name + NOR YEL"��������լ��\n" NOR);
    return 1;
}

public void confirm_cession(string yn)
{
    object me, ob;

    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N�����룬��$nҡͷ���������ٿ���һ�°ɡ�\n" NOR, me, ob);
        me->delete_temp("cession_house");
        return;
    }

    message_vision(HIC "$N�����룬��$n��ͷ�����������ɣ��Ҿ����ˡ�\n" NOR, me, ob);
    tell_object(me, HIW "��������լ���룺" NOR);
    input_to("check_password", 1, me);
    return;
}

private int do_dismantle(string arg)
{
    int i;
    object me, ob;
    string who, name, *key;
    mapping build;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s %s", who, name) != 2)
        return notify_fail(HIW "ָ���ʽ��dismantle <���ID> <��լ����>\n" NOR);

    build = me->query("house/build");
    if(sizeof(build) == 0)
        return notify_fail(YEL "���н������լ��\n" NOR);

    if(who != me->query("id"))
        return notify_fail(YEL "��ֻ�ܲ���Լ���ӵ�е���լ��\n" NOR);

    key   = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(build[key[i]] != name)
            continue;
        if(build[key[i]] == name)
        {
            if(key[i] == "bang" || key[i] == "xian")
            {
                if(!wizardp(me))
                {
                    message("vision", ob->name(1) + "ҡ��ҡͷ����"
                                    + me->name() + "����С��˵�˼��仰��\n",
                                            environment(me), ({ me, ob }));
                    tell_object(me, YEL + ob->name(1) + "ҡͷ������"
                                    HIW + name + NOR YEL"��������լ"
                                        "�ǲ����Բ���ġ�\n" NOR);
                    return 1;
                }
                message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "��ͷ��������ӵ�еġ�"
                                HIY + name + HIC "�����������"
                                    "ȷ����(y/n)��\n" NOR);
               me->set_temp("dismantle_house", key[i]);
                input_to("confirm_dismantle", me);
                return 1;
            }

            if(key[i] == "user")
            {
                message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                                  "����С��˵�˼��仰��\n", environment(me),
                                                            ({ me, ob }));
                tell_object(me, HIC + ob->name(1) + "��ͷ��������ӵ�еġ�"
                                HIY + name + HIC "�����������"
                                    "ȷ����(y/n)��\n" NOR);
	            me->set_temp("dismantle_house", key[i]);
	            input_to("confirm_dismantle", me);
                return 1;
            }
        }
    }

    message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, YEL + "\n" + ob->name(1) + "ҡͷ�������н������"
                    HIW + name + NOR YEL"��������լ��\n" NOR);
    return 1;
}

public void confirm_dismantle(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        message_vision(YEL "$N�����룬��$nҡͷ���������ٿ���һ�°ɡ�\n" NOR, me, ob);
        me->delete_temp("dismantle_house");
        return;
    }
    message_vision(HIC "$N�����룬��$n��ͷ�����������ɣ��Ҿ����ˡ�\n" NOR, me, ob);
    tell_object(me, HIW "��������լ���룺" NOR);
    input_to("check_password", 1, me);
    return;
}

public void check_password(string passwd, object me)
{
    object ob, who;
    string pass, type, arg;
    mapping house, temp;

    if(me->query_temp("cession_house/type"))
    {
        type = me->query_temp("cession_house/type");
    }
    else
        if(me->query_temp("dismantle_house"))
    {
        type = me->query_temp("dismantle_house");
    }
    else
        if(me->query_temp("rebuild_house/the_type"))
    {
        type = me->query_temp("rebuild_house/the_type");
    }
    else
    {
        tell_object(me, "���Ͳ����������ֹ��\n");
        return;
    }

    house = me->query("house/" + type);
    pass = house["pass"];
    if(passwd != pass)
    {
        tell_object(me, HIR "�������\n" NOR);
        reset_all_static();
        return;
    }

    ob = this_object();
    if(me->query_temp("cession_house"))
    {
       temp = me->query_temp("cession_house");
        arg  = temp["type"];

        tell_object(me, HIG "������ȷ����ʼת��......\n\n" NOR);
        if(!objectp(who = present(temp["name"], environment(me)))
            || !userp(who)
            || !interactive(who)
            || !who->is_livings())
        {
            tell_object(me, YEL "ת��ʧ�ܣ�����û������ˡ�\n" NOR);
            return;
        }

        HOUSE_D->do_cession(me, who, arg);
        me->delete_temp("cession_house");
        return;
    }
    else
        if(me->query_temp("dismantle_house"))
    {
        arg = me->query_temp("dismantle_house");
        tell_object(me, HIG "������ȷ����ʼ���......\n\n" NOR);
        HOUSE_D->do_dismantle(me, arg);
        me->delete_temp("dismantle_house");
        return;
    }
    else
        if(me->query_temp("rebuild_house"))
    {
        tell_object(me, HIG "������ȷ����ʼ�Ľ�......\n\n" NOR);
        build_house(sprintf("%s on %s",
                        me->query_temp("building_house/name"), the_base));
        return;
    }
    else
    {
        tell_object(me, "���Ͳ�����������ֹ��\n");
        return;
    }
}

private void reset_all_static()
{
    the_value = 0;
    max_laodu = 0;
    the_base = "";
    the_name = "";
    the_type = "";
    npc_data = ([]);
}

private int add_vip_count(string arg)
{
    int i, how;
    object me, ob, room, huyuan;
    mapping build, house;
    string *key, msg;

    if(!arg || arg == "")
        return notify_fail(HIW "ָ���ʽ��addvips <��լ����>\n" NOR);

    me = this_player();
    ob = this_object();
    build = me->query("house/build");
    if(!build)
    {
        tell_object(me, YEL "���н����������լ��\n" NOR);
        return 1;
    }
    if(mapp(build) && sizeof(build) > 0)
    {
        key = keys(build);
        for(i = 0; i < sizeof(key); i++)
        {
            if(build[key[i]] == arg)
            {
                house = me->query("house/" + key[i]);
                me->set_temp("house_addvips/type", key[i]);
                break;
            }
        }
        if(!house)
        {
            tell_object(me, YEL "���н����������լ��\n" NOR);
            return 1;
        }
    }
    if(mapp(house) && sizeof(house) > 0)
    {
        room = get_object(house["entry"]);
        huyuan = get_object(room->query("huyuan"));    //���һ�Ժ
        huyuan->restore();
        how = huyuan->query("vip_limit");
        if((int)how <= 0)
            how = VIP_ORIGIN;
    }

    if(how >= VIP_LIMIT)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                            "����С��˵�˼��仰��\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "\n%sҡͷ������ġ�%s����ǰ�Ĺ���޶�"
                                    "�Ѵ�%sλ���޷��������ˡ�\n" NOR,
                                        ob->name(1), arg, chinese_number(how)));
        return 1;
    }

    if(me->query("bank/gold") < VIP_VALUE)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                            "����С��˵�˼��仰��\n", environment(me),
                                                    ({ me, ob }));
        tell_object(me, sprintf(YEL "\n%sҡͷ�������µĴ���֧���������޶�"
                                    "�ķ��ã�ȥ�湻%s���ƽ������ɡ�\n" NOR,
                                        ob->name(1), chinese_number(VIP_VALUE)));
        return 1;
    }

    message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                      "����С��˵�˼��仰��\n", environment(me),
                                                ({ me, ob }));
    tell_object(me, sprintf(HIC "\n%s��ͷ������ġ�%s����ǰ����޶��� " HIW "%s"
                            HIC " λ��\n���뻨��" HIY "%s"
                            HIC "���ƽ𽫹���޶����䵽 "
                            HIG "%s" HIC " λ��(y/n)��\n" NOR,
                                ob->name(1), arg,
                                chinese_number(how),
                                chinese_number(VIP_VALUE),
                                chinese_number(how + 1)));

    me->set_temp("house_addvips/huyuan", room->query("huyuan"));
    input_to("confirm_addvips", me);
    return 1;
}

public void confirm_addvips(string yn)
{
    object me, ob;
    me = this_player();
    ob = this_object();

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        me->delete_temp("house_addvips");
        message_vision(YEL "$N�����룬��$nҡͷ���������ٿ���һ�°ɡ�\n" NOR, me, ob);
        return;
    }

    message_vision(HIC "$N�����룬��$n��ͷ�����������ɣ��Ҿ����ˡ�\n" NOR, me, ob);
    HOUSE_D->add_vip_limit(VIP_VALUE, me, ob);
    return;
}
