// /adm/daemons/housed.c סլϵͳ�ܿس���
// By Alf, Last Update 2003.0730
// Modify By Alf@Syzf, Last Update 2005.0402
// ����ԭַ�Ľ���������޹���

/*
 ������Ŀǰ�������ļ����ã�
/cmds/adm/conhouse.c                            �ѽ���լת�����ָ��
/cmds/arch/shenxian.c                           �������Ϊɢ�ɵ�ָ��
/cmds/imm/home.c                                ɢ��ֱ�ӷ��ؾ���ָ��
/cmds/bang/bchuanwei.c                          ��Ұ�������λָ��
/cmds/bang/btuoli.c                             ���������Ұ��ָ��
/cmds/usr/checkhouse.c                          �鿴������լ���ָ��

/adm/npc/bunong.c                               ���������լ�����NPC

/inherit/room/house_base.c                      լ���ؿ�ģ���ļ�
/inherit/room/house_door.c                      ��լ����ģ���ļ�
/inherit/room/house_room.c                      ��լ����ģ���ļ�
/inherit/char/huyuan.c                          ��լ��Ժģ���ļ�

լ���ؿ���Ŀ¼��/clone/house/base/
�����ļ�Ӧ�߲�����can_build                     �ɹ�������լ����
                  max_build                     ���ɽ���լ��Ŀ

��լģ����Ŀ¼��/clone/house/type/����/����/  ���ͷ�user��bang��xian�����ƿɸ�
�����ļ�Ӧ�߲�����
���ų����ļ���set_exits                         ����լ�ӿڵ����ƣ�ɢ�ɾ����޴��
              set_entry                         ����լ�ӿڵ��ļ���ɢ�ɾ����޴��
              forbid_exits                      ����լ�ӿڵ����ƣ�ɢ�ɾ���ר���
                                                ɢ�ɾ�����������ר�õ�valid_leave
              huyuan                            ��լ��Ժ�ļ�·��
              max_laodu                         ���ŵ�����ι̶�
              now_laodu                         ���ŵĵ�ǰ�ι̶�
���������ļ���resource/water                    ����������ˮ����
���г����ļ���owner                             ��լ���˵�ID����ʼΪOWNER���ɲ��裩
              owner_name                        ��լ������������ʼΪĳ�ˣ��ɲ��裩

�ѽ���լ���Ŀ¼��/clone/house/user/��լ����ID/
                  /clone/house/xian/��լ����ID/
                  /clone/house/bang/��������/

�����������������ļ���
/include/globals.h                              ȫ�ֱ��������ļ�
/adm/daemons/updated.c                          ϵͳ�����ػ�����
/adm/daemons/factiond.c                         �����趨�ػ�����
*/

inherit F_DBASE;
#include <ansi.h>
#include "include/banned_name.h"                                //������������б�
#include "include/house_typez.h"                                //����ɽ������б�
#include "include/house_basez.h"                                //������õؿ��б�

#define CMD_RM      "/cmds/wiz/rm"
#define CMD_CP      "/cmds/wiz/cp"
#define HOUSE_DIR   "/clone/house/"
#define SOURCE_DIR  "/clone/house/type/"                        //��լģ��Ŀ¼
#define BASE_DIR    "/clone/house/base/"                        //լ���ؿ�Ŀ¼
#define VIP_ORIGIN  12                                          //��ʼ�������

#define FACTION_D    "/adm/daemons/factiond"

void sys_info(string msg);                                      //ϵͳ��Ϣ��ʾ
public mapping *query_house_type();                             //���ط����б�
public mapping *query_house_base();                             //���صؿ��б�
public int show_type(object me);                                //��ʾ�ɽ�����
public int choice_type(string arg, object me);                  //ѡ���췿��
public int show_base(object me);                                //��ʾ���õؿ�
public int choice_base(string arg, object me);                  //ѡ����ؿ�
public int build_house(object me);                              //������ѡ��լ
public int do_cession(object me, object ob, string arg);        //ת����ѡ��լ
public int do_dismantle(object me, string arg);                 //���ĳ����լ
public int do_dismantle_all(object me);                         //���������լ
public int do_short(object me, string arg);                     //�趨��������
public int do_long(object me);                                  //�趨��������
public int do_item(object me, string arg);                      //�趨������Ʒ
public int look_house_door(string arg, object me, object ob);   //�鿴����״��
public int push_house_door(string arg, object me, object ob);   //���Ž�������
public int jiagu_house_door(string arg, object me, object ob);  //�ӹ̴����ζ�
public int break_house_door(string arg, object me, object ob);  //������ͼ����
public int add_guest(string arg, object me, object ob);         //ά������б�
public int add_vip_limit(int value, object me, object ob);      //����������
public int ask_guest(object me, object ob);                     //��ѯ�Ƿ���
public int invite_guest(object me, string arg);                 //����ĳ������
public int modify_huyuan(string arg, object me, object ob);     //�޸Ļ�Ժ����
public int ask_huyuan_level(object me, object ob);              //��ѯ��Ժ�ȼ�
public int ask_huyuan_faction(object me, object ob);            //��ѯ��Ժ����
public int shenji_huyuan(string arg, object me, object ob);     //������Ժ�ȼ�
public int set_huyuan_skill(string arg, object me, object ob);  //���û�Ժ����
private int add_entry(object me, string arg);                   //����ؿ����
private int del_entry(object me, string arg);                   //ɾ���ؿ����
public int get_long(string msg, string arg, object me);         //�༭��������
public int no_dismantle(object me, object ob, string arg);      //�����ֻ����
public void confirm_setskill(string yn, object me, object ob);  //ȷ���趨����
public string random_generation_password(int passlen);          //�����������

//���ó�����ϵͳƵ����������
void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "���ݾ���");
}

//ϵͳ��Ϣ��ʾ
void sys_info(string msg)
{
    CHANNEL_D->do_channel(this_object(), "sys", msg);
}

//���ط����б��ɹ��ⲿ�������
public mapping *query_house_type()
{
    return house_type;
}

//���صؿ��б��ɹ��ⲿ�������
public mapping *query_house_base()
{
    return house_base;
}

//��ʾ��ǰ�ɹ�����ķ����б�
public int show_type(object me)
{
    int i;
    string type, msg;

    msg = HIC"\n��"HIY + MUD_NAME + HIC"��Ŀǰ�ɹ��������լ�����У�\n" NOR;
    msg += HIG "�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n" NOR;

    for (i = 0; i < sizeof(house_type); i++)
    {
        if(house_type[i]["type"] == "user") type = "���סլ";
        if(house_type[i]["type"] == "bang") type = "���פ��";
        if(house_type[i]["type"] == "xian") type = "ɢ�ɾ���";
        msg += sprintf(HIW "���ƣ�" HIY "%-10s" NOR
                       HIW "���" HIY "%-10s" NOR
                       HIW "������" HIY "%-4d" NOR
                       HIW "��ۣ�" HIY"%-6d���ƽ�\n" NOR,
                       house_type[i]["name"],
                       type,
                       house_type[i]["rooms"],
                       house_type[i]["value"]);
    }

    msg += HIG "�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n" NOR;
    me->start_more(msg);
    return 1;
}

//ѡ����Ҫ����ķ���
public int choice_type(string arg, object me)
{
    int i, value;
    string name, code, type, entry;

    if(!arg)
        return notify_fail("��ѡ��һ����ȷ����լ���͡�\n");

    for(i = 0; i < sizeof(house_type); i++)
    {
        if(arg != house_type[i]["name"])
            continue;
        code  = house_type[i]["code"];
        type  = house_type[i]["type"];
        name  = house_type[i]["name"];
        entry = house_type[i]["entry"];
        value = house_type[i]["value"];
    }

    set_temp("building_house/name", name, me);
    set_temp("building_house/code", code, me);
    set_temp("building_house/type", type, me);
    set_temp("building_house/entry", entry, me);
    set_temp("building_house/value", value, me);
    set_temp("building_house/val_t", value, me);
    tell_object(me, HIC "��ѡ���ˡ�"HIW + name + HIC"��������լ�������Ϊ "
                    HIY + value + " ���ƽ�" NOR);
    return 1;
}

//��ʾ��ǰ�����ڽ����ĵؿ��б�
public int show_base(object me)
{
    int i, j;
    object base;
    string msg, type;

    msg = HIC "\n��"HIY + MUD_NAME + HIC"��Ŀǰ�ɹ�������լ�ĵؿ��У�\n" NOR;
    msg += HIG "�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n" NOR;

    for (i = 0; i < sizeof(house_base); i++)
    {
        if(house_base[i]["type"] == "user") type = "���סլ";
        if(house_base[i]["type"] == "bang") type = "���פ��";
        if(house_base[i]["type"] == "xian") type = "ɢ�ɾ���";

        base = get_object(BASE_DIR + house_base[i]["file"]);
        if( query("house_build", base) >= query("max_build", base) )
            continue;
        j=query("max_build", base)-query("house_build", base);
        msg += sprintf(HIW "���ƣ�" HIY "%-12s" NOR
                       HIW "����" HIY "%-8s" NOR
                       HIW "�ɽ���" HIY "%-10s" NOR
                       HIW "ʣ�ࣺ" HIY "%-2d" NOR
                       HIW "�ؼۣ�" HIY "%-6d���ƽ�\n" NOR,
                       house_base[i]["name"],
                       house_base[i]["place"], type, j,
                       house_base[i]["value"]);
    }

    msg += HIG "�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n" NOR;
    me->start_more(msg);
    return 1;
}

//ѡ����Ҫ���췿�ݵĵؿ�
public int choice_base(string arg, object me)
{
    int i;
    mapping base;

    if(!arg)
        return notify_fail("��ѡ��һ����ȷ�ĵؿ����ơ�\n");

    for(i = 0; i < sizeof(house_base); i++)
    {
        if(house_base[i]["name"] == arg)
        {
            base = ([
                        "name"  : house_base[i]["name"],
                        "place" : house_base[i]["place"],
                        "file"  : BASE_DIR + house_base[i]["file"],
                        "value" : house_base[i]["value"],
                    ]);
            set_temp("building_house/base", base, me);
            tell_object(me, HIC "��ѡ���ˡ�"HIW + arg + HIC"����һ�ؿ飬��ؼ�Ϊ "
                            HIY + base["value"] + " ���ƽ�" NOR);
            return 1;
        }
    }

    tell_object(me, YEL "û�С�"HIW + arg + NOR YEL"������ؿ顣\n" NOR);
    return 1;
}

//��ѡ���ĵؿ��Ͻ������ѡ���͵���լ
public int build_house(object me)
{
    int i, j;
    string name, type, file, code, path, entry, zhuan, pass;
    mapping house, build, base, npc_data;
    object obj;
    string *room, *key;

    name=query_temp("building_house/name", me);
    base=query_temp("building_house/base", me);
    type=query_temp("building_house/type", me);
    code=type+"/"+query_temp("building_house/code", me)+"/";

    if(type == "bang")
    {
        path=HOUSE_DIR+type+"/"+query("bang/name", me);
    }
    if(type == "user" || type == "xian")
    {
        path=HOUSE_DIR+type+"/"+query("id", me);
    }

    if( !query_temp("building_house/path", me) )
        file  = SOURCE_DIR + code;
    else
        file=query_temp("building_house/path", me)+"/";

    entry=path+"/"+query_temp("building_house/entry", me);
    house = ([]);
    if( !query("house/build", me) )
        build = ([]);
    else
        build=query("house/build", me);

    reset_eval_cost();
    CMD_CP->copy_dir(file, path);

    room = get_dir(path + "/");
    for(i = 0; i < sizeof(room); i++)
    {
        reset_eval_cost();
        obj = load_object(path + "/" + room[i]);
        set("owner",query("id",  me), obj);//��������Ĺ�����ID
        if(obj->is_house_huyuan()                           /*����������ǻ�Ժ*/
             && query("owner_name", obj) == "ĳ��"/*��ת����ԭ������*/
             && query("set_skill/owner", obj) == "HOUSE_D")/*δ�Ļ�����������*/
        {
            npc_data=query_temp("rebuild_house/npc_data", me);
            if(mapp(npc_data) && sizeof(npc_data) > 0)  //ԭַ�Ľ����ܲ���
            {
                reset_eval_cost();
                key = keys(npc_data);
                for(j = 0; j < sizeof(key); j++)
                {
                    if(key[j] == "level"                /*���ܵȼ�ȡ�ϸ��߱���*/
                         && npc_data[key[j]]>query("set_skill/level", obj) )
                            set("set_skill/level", npc_data[key[j]], obj);
                    else
                        if(key[j] == "skill")
                            set("generation_skill/code", npc_data[key[j]], obj);
                    else
                        set(key[j], npc_data[key[j]], obj);
                }
                //����ԭ�м�����������
                FACTION_D->gen_npc(obj,query("generation_skill/code", obj));
            }
            else
                FACTION_D->gen_npc(obj, 0);                 //���ѡ��ĳһ�ּ���
        }
        if( query("max_laodu", obj)/*�����ζ�ȡ�ϸ��߱���*/
             && query("max_laodu", obj)<query_temp("rebuild_house/max_laodu", me) )
        {
            set("max_laodu",query_temp("rebuild_house/max_laodu",  me), obj);
            set("now_laodu",query_temp("rebuild_house/max_laodu",  me), obj);
        }
        if(type == "bang")
        {
            set("owner_name",query("bang/name",  me), obj);//�������Ϊ��������
            if(obj->is_board())
            {
                obj->set_name(query("bang/name", me)+"�İ�����԰�",({"board"}));
                set("location", path+"/xiaoting", obj);
            }
        }
        else
            if(type == "user" || type == "xian")
        {
            set("owner_name", me->name(1), obj);//��������Ϊ��������
        }
        set("path", path, obj);
        set("type", type, obj);
        obj->save();
        destruct(obj);
    }

    house += ([
        "name":query_temp("building_house/name", me),
        "code":query_temp("building_house/code", me),
        "value":query_temp("building_house/value", me),
        "zhuan":query_temp("building_house/zhuan", me),
        "entry" : entry,
        "path"  : path,
        "base"  : base,
    ]);

    pass = random_generation_password(8);
    house += ([ "pass" : pass, ]);
    build+=([type:query_temp("building_house/name", me),]);
    if( query_temp("building_house/build", me )
         && !query_temp("wiz_zhuan", me))//�б�־����ʻ��ڿ�Ǯ
            addn("bank/gold", -house["value"], me);

//ϵͳ��־��¼
    log_file("money/house", sprintf("%s��%s(%s)��%s����%sһ�ף�"
                                    "���� %d ���ƽ�\n", log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          base["name"],
                                                          name,
                                                          house["value"]));

    if( query_temp("rebuild_house/the_value", me))//�Ľ��ܼ�ֵ����Ͼ�լ��ֵ
        house["value"]+=query_temp("rebuild_house/the_value", me);
    set("house/"+type, house, me);
    set("house/build", build, me);
    add_entry(me, type);

    tell_object(me, BEEP + BLINK + HIC "\n��ϲ���������Ѿ��ڡ�"
                                   HIW + base["name"] + HIC"��ӵ��һ�ס�"
                                   HIY + name + HIC"���ˣ�\n" NOR);

    tell_object(me, HIW "������լ�ı���Ϊ��"HIY + pass + HIW"�������μ�"
                        "�����Ʊ��ܺ�������롣\n" NOR);
//ϵͳ��Ϣ��ʾ
    sys_info(me->name(1)+"("+query("id", me)+")��"
                         + base["name"] + "ӵ����һ��" + name + "��");

    delete_temp("building_house", me);
    me->save();
    return 1;
}

//�½���լ�깤�����������ؿ�������Ӧ���
private int add_entry(object me, string arg)
{
    object room, door;
    mapping type;
    string entry;

    if( !query("house/"+arg, me) )
        return 1;

    type=query("house/"+arg, me);
    room  = get_object(type["base"]["file"]);
    entry = type["entry"];
    if( query("can_build", room) == "bang" )
    {
        set("exits/enter", entry, room);
    }
    else
        if( query("can_build", room) == "user"
             || query("can_build", room) == "xian" )
    {
        set("exits/"+query("id", me), entry, room);
    }
    addn("house_build", 1, room);
    room->save();

    door  = get_object(type["entry"]);
    entry = type["base"]["file"];
    set("exits/out", entry, door);
    door->save();
    return 1;
}

//������լ���������ԭ���ؿ�ɾ����Ӧ���
private int del_entry(object me, string arg)
{
    int i;
    object room;
    mapping type;

    if( !query("house/"+arg, me) )
        return 1;

    type=query("house/"+arg, me);
    room = get_object(type["base"]["file"]);
    if( query("can_build", room) == "bang" )
    {
        delete("exits/enter", room);
    }
    else
        if( query("can_build", room) == "user"
             || query("can_build", room) == "xian" )
    {
        delete("exits/"+query("id", me), room);
    }
    addn("house_build", -1, room);
    room->save();
    return 1;
}

//���Լ�ӵ�е�ĳ����լת�ø�����
public int do_cession(object me, object ob, string arg)
{
    int i, value, new_value, v1, nv1;
    mapping house, new_house;
    string zhuan, entry;

    house=query("house/"+arg, me);
    if(!house)
    {
        tell_object(me, YEL "���н����������լ��\n" NOR);
        return 1;
    }

    if( query("house/"+arg, ob) )
    {
        tell_object(me, YEL "\nת��ʧ�ܣ�" + ob->name() +
                            "�Ѿ�ӵ��������լ�ˡ�\n" NOR);
        return 1;
    }

    if(arg == "user" && wizhood(ob) != "(player)")
    {
        tell_object(me, YEL + "\nת��ʧ�ܣ�" + ob->name() +
                              "�Ѿ�������Ҫ��Щ���������ˡ�\n" NOR);
        return 1;
    }

    if(arg == "xian" && !wizardp(ob) && wizhood(ob) != "(immortal)")
    {
        tell_object(me, YEL + "ת��ʧ�ܣ�\n" + ob->name() +
                        "��û��λ���Ͻ��ɰ࣬���ܻ�ȡ������լ��\n" NOR);
        return 1;
    }

    if( arg == "bang" && query("bang/class", ob) != 1 )
    {
        tell_object(me, YEL + "ת��ʧ�ܣ�\n" + ob->name() +
                        "��δ���ϰ������������ܻ�ȡ������լ��\n" NOR);
        return 1;
    }

    if( !query_temp("cession_house/name", me) )
        zhuan = house["zhuan"];
    else
        zhuan=me->name(1)+"("+query("id", me)+")";

    value = house["value"];
    if(zhuan == "HOUSE_D")
    {
        new_value = value;
              nv1 = 0;
               v1 = 0;
    }
    else
    {
        new_value = value + value/10;
              nv1 = new_value;
               v1 = value;
        if( query("bank/gold", ob)<new_value )
        {
            tell_object(me, YEL + "\n\nת��ʧ�ܣ�" + ob->name() +
                                  "��Ǯׯ����֧���ܼ�"
                            HIY + chinese_number(new_value) + "���ƽ�" NOR
                            YEL "�ķ�����ֵ�������ѡ�\n" NOR);
            tell_object(ob, YEL "\n\nת��ʧ�ܣ����Ǯׯ����֧���ܼ�"
                            HIY + chinese_number(new_value) + "���ƽ�" NOR
                            YEL "�ķ�����ֵ�������ѡ�\n" NOR);
            return 1;
        }
    }

    for(i = 0; i < sizeof(house_type); i++)
    {
        if(house["name"] != house_type[i]["name"])
            continue;
        entry = house_type[i]["entry"];
    }

    new_house = ([
        "name"  : house["name"],
        "code"  : house["code"],
        "base"  : house["base"],
        "path"  : house["path"],
        "type"  : arg,
        "entry" : entry,
        "value" : new_value,
        "zhuan" : zhuan,
        "build" : "cession",
    ]);

    set_temp("building_house", new_house, ob);

    if(arg == "bang")   //���פ����������ֻ�������趨
    {
        no_dismantle(me, ob, arg);
    }
    else
        if(arg == "user" || arg == "xian")
    {
        build_house(ob);        //���챻ת���ߵ�����լ
        do_dismantle(me, arg);  //���������ԭ�еľ���
    }

    if(nv1 > 0)
    {
        tell_object(ob, BEEP + BLINK + HIC "������ֵ�������ѹ���"
                             + HIY + chinese_number(nv1) + "���ƽ�"
                               HIC "�Ѵ����Ǯׯ�ʻ��ڿ۳���\n" NOR);
    }

    addn("bank/gold", v1, me);
    if(v1 > 0)
    {
        tell_object(me, BEEP + BLINK + HIC "ת�óɹ���������ֵ"
                             + HIY + chinese_number(v1) + "���ƽ�"
                               HIC "��ת�����Ǯׯ�ʻ��ڡ�\n" NOR);
    }
    return 1;
}

//����ѡ����ĳ����լ���
public int do_dismantle(object me, string arg)
{
    int i, j;
    string path, *key, *room;
    mapping build, type;
    object obj;

    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;

    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == arg)
        {
            type=query("house/"+arg, me);
            path = type["path"];
            room = get_dir(path + "/");
            for(j = 0; j < sizeof(room); j++)
            {
                reset_eval_cost();
                obj = get_object(path + "/" + room[j]);
                destruct(obj);
            }
            del_entry(me, arg);
            CMD_RM->rm_dir(path);
            CMD_RM->rm_dir(DATA_DIR + path);
            tell_object(me, BEEP + BLINK + HIR "\n���ڡ�"
                                           HIW + type["base"]["name"] +
                                           HIR"���ġ�"HIY + type["name"] +
                                           HIR"���Ѿ��������ˣ�\n" NOR);
            //ϵͳ��Ϣ��ʾ
            sys_info(me->name(1)+"("+query("id", me)+")��"
                                 + type["base"]["name"] + "��"
                                 + type["name"] + "���Ѳ����");
            //ϵͳ��־��¼
            log_file("money/house", sprintf("%s��%s(%s)��%s��%s�����\n",
                                                          log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          type["base"]["name"],
                                                          type["name"]));
            delete("house/"+arg, me);
            map_delete(build, key[i]);
            set("house/build", build, me);
            if(sizeof(build) == 0)
                delete("house", me);
            return 1;
        }
    }
    return 1;
}

//���ݲ������ֻ�����趨������Ϣ�����ڰ�����λ�����ʽ�����
public int no_dismantle(object me, object ob, string arg)
{
    int i;
    object obj;
    string path, pass, *key, *room;
    mapping house, build, type;

    //��������˵��й�����
    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;
    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == arg)
        {
            type=query("house/"+arg, me);
            path = type["path"];
            pass = type["pass"];
            delete("house/"+arg, me);
            map_delete(build, key[i]);
            set("house/build", build, me);
            if(sizeof(build) == 0)
                delete("house", me);
            me->save();
        }
    }

    //������լ������������
    path=query_temp("building_house/path", ob);
    room = get_dir(path + "/");
    for(i = 0; i < sizeof(room); i++)
    {
        obj = get_object(path + "/" + room[i]);
        if(arg == "bang")
        {
            set("owner_name",query("bang/name",  ob), obj);
        }
        else
            if(arg == "user" || arg == "xian")
        {
            set("owner_name", ob->name(1), obj);
        }
        set("owner",query("id",  ob), obj);
        set("path", path, obj);
        set("type", arg, obj);
        obj->save();
        destruct(obj);
    }

    //���������˵��й�����
    house = ([]);
    if( !query("house/build", ob) )
        build = ([]);
    else
        build=query("house/build", ob);

    house += ([
        "name":query_temp("building_house/name", ob),
        "code":query_temp("building_house/code", ob),
        "value":query_temp("building_house/value", ob),
        "zhuan":query_temp("building_house/zhuan", ob),
        "entry":query_temp("building_house/entry", ob),
        "path":query_temp("building_house/path", ob),
        "base":query_temp("building_house/base", ob),
        "pass"  : pass,
    ]);

    build+=([arg:query_temp("building_house/name", ob),]);
    set("house/"+arg, house, ob);
    set("house/build", build, ob);
    delete_temp("building_house", ob);
    ob->save();

    //ϵͳ��Ϣ��ʾ
    sys_info(me->name(1)+"("+query("id", me)+")��"+
             ob->name(1)+"("+query("id", ob)+")�����˷������ӡ�");

    //ϵͳ��־��¼
    log_file("money/house", sprintf("%s��%s(%s)��%s(%s)"
                                    "�����˷������ӡ�\n", log_time(),
                                                          me->name(1),
                                                          query("id", me),
                                                          ob->name(1),
                                                          query("id", ob)));
    return 1;
}

//������ɱ���嵵��ԭ�е�������լ�����Զ����
public int do_dismantle_all(object me)
{
    int i;
    string *key, arg;
    mapping build;

    build=query("house/build", me);
    if(sizeof(build) == 0)
        return 1;

    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        arg = key[i];
        do_dismantle(me, arg);
        continue;
    }
    return 1;
}

//�趨��������
public int do_short(object me, string arg)
{
    if(!arg)
    {
        tell_object(me, "ָ���ʽ��setname <��������>\n");
        return 1;
    }
    if(CHINESE_D->check_control(arg))
        return notify_fail("���ֲ����п��Ʒ���\n");
    if(CHINESE_D->check_space(arg))
        return notify_fail("���ֱ��費���ո�\n");
    if(CHINESE_D->check_return(arg))
        return notify_fail("���ֱ��費���س�����\n");
    if(!CHINESE_D->check_chinese(arg))
        return notify_fail("���ֱ���ʹ�����ģ�\n");
    if(strlen(arg) > 14)
        return notify_fail("�����ֻ���߸����֣�\n");

    tell_object(me, "���÷�������Ϊ��" + arg);
    tell_object(me,"...�ɹ���\n");
    set("short", arg, environment(me));
    environment(me)->save();
    return 1;
}

//�趨������Ʒ���ƣ�Ŀǰ�����Ų�ˮһ�
public int do_item(object me, string arg)
{
    string item, desc;
    object room = environment(me);

    if(!arg || sscanf(arg, "%s %s", item, desc) != 2)
        return notify_fail("ָ���ʽ��setitem <��Ʒ> <����>\n");
    if(item != "��ˮ")
        return notify_fail("Ŀǰֻ���趨����ˮ�������ơ�\n");
    if( !query("resource/water", room) )
        return notify_fail("ֻ�п����ڲſ������ò�ˮ���ơ�\n");

    desc = trans_color(desc);
    if(!CHINESE_D->check_chinese(filter_color(desc)))
        return notify_fail("��Ʒ���Ʊ���ʹ�����ģ�\n");
    if(CHINESE_D->check_control(filter_color(desc)))
        return notify_fail("��Ʒ���Ʋ����п��Ʒ���\n");
    if(CHINESE_D->check_space(filter_color(desc)))
        return notify_fail("��Ʒ���Ʊ��費���ո�\n");
    if(strlen(filter_color(desc)) > 14)
        return notify_fail("��Ʒ�������Ϊ�߸����֣�֧����ɫ���롣\n");
    if(member_array(filter_color(desc), banned_name) != -1)
        return notify_fail("�������ֲ�̫�ð�......\n");
    set("resource/water", desc, room);
    room->save();
    tell_object(me, "�趨��ˮ����Ϊ��" + desc + NOR"��...�ɹ���\n");
    return 1;
}

//��ʼ�趨������ϸ����
public int do_long(object me)
{
    string arg = "";

    tell_object(me, "�������Ϊ���У����������� . ��ʾ��������һ���׻��Զ��������ո�\n");
    tell_object(me, "------------------------------------------------------------\n");
    input_to("get_long", arg, me);
    return 1;
}

//����༭������ϸ����
public int get_long(string msg, string arg, object me)
{
    int i=query("long_line", environment(me));

    if(msg == ".")
    {
        if(i > 5)
        {
            write("�趨ʧ�ܣ��������ܳ������С�\n");
            delete("long_line", environment(me));
            return 1;
        }
        else
        {
            set("long", arg, environment(me));
            delete("long_line", environment(me));
            environment(me)->save();
            tell_object(me, "�趨��������...�ɹ���\n");
            return 1;
        }
    }

    if(strlen(msg) > 60)
    {
        write("ÿ���������Ϊ��ʮ���������ո����㣩�����������뱾�С�\n");
        input_to("get_long", arg, me);
        return 1;
    }
    arg += msg + "\n";
    addn("long_line", 1, environment(me));
    input_to("get_long", arg, me);
    return 1;
}

//�鿴���ŵ�ǰ״���������ɲ鿴����ǰ������ζ�
public int look_house_door(string arg, object me, object ob)
{
    int i;
    string msg;

    if(!arg || arg == "")
        return 0;

    if(arg != "men"
        && arg != "door"
        && arg != "��"
        && arg != "����")
            return 0;

    if( query("id", me) == query("owner", ob) )
    {
        tell_object(me, HIW "Ŀǰ���ŵ�����ζ�Ϊ��"HIY
                        +chinese_number(query("max_laodu", ob) )
                        + HIW"���㣬��ǰ�ζ�Ϊ��"HIY
                        +chinese_number(query("now_laodu", ob) )
                        + HIW"���㡣\n" NOR);
        if( query("type", ob) != "xian" )
        {
            tell_object(me, "������ûƽ����ӹ�(jiagu)���ţ�"
                            "ÿһ���ƽ�������һ���ζȡ�\n");
        }
        return 1;
    }
    else
    {
        i=query("now_laodu", ob);
        if(i <= 0)
            msg = "��ȫȻ�ٻ�";
        else
            if(i < 100)
                msg = "�Ѳ���һ��";
        else
            if(i >= 100 && i < 300)
                msg = "��ҡҡ��׹";
        else
            if(i >= 300 && i < 500)
                msg = "�����Ķ�";
        else
            if(i >= 500 && i < 1000)
                msg = "�����ɿ�";
        else
            if(i >= 1000 && i < 3000)
                msg = "�����ʵ";
        else
            if(i >= 3000 && i < 6000)
                msg = "��ʵ�ɿ�";
        else
            if(i >= 6000 && i < 10000)
                msg = "��Ϊ�ι�";
        else
            if(i >= 10000 && i < 20000)
                msg = "������";
        else
            if(i >= 20000 && i < 30000)
                msg = "�β�����";
        else
            if(i >= 30000 && i < 1000000)
                msg = "��������";
        else
            if(i >= 1000000)
                msg = "��������";

        tell_object(me,"����"+query("owner_name", ob)+
                        "�Ĵ��ţ�����ȥ�ƺ�" + msg + "��\n");
        return 1;
    }
}

//���������ϵĻƽ����ӹ̴��ŵ��ζ�
public int jiagu_house_door(string arg, object me, object ob)
{
    object gold;
    mapping house;
    int how, value;

    if( query("id", me) != query("owner", ob) )
        return notify_fail("ʲô��\n");

    if(!arg || sscanf(arg, "%d gold", how) != 1)
        return notify_fail("��Ҫ���������ƽ�(" HIG "jiagu *** gold" NOR
                           ")���ӹ̴��ŵ��ζȣ�\n");

    if(!(gold = present("gold_money", me)))
        return notify_fail("�����Ϻ���û�д��ƽ�ɣ�\n");

    if(how < 1)
        return notify_fail("��Ҫ���������ƽ�(" HIG "jiagu *** gold" NOR
                           ")���ӹ̴��ŵ��ζȣ�\n");

    if((int)gold->query_amount() < how)
        return notify_fail("�����Ϻ���û�д���ô��Ļƽ�ɣ�\n");

    if( query("type", ob) == "xian" )
        return notify_fail("��լ���ŷ����������ƻ��������ټӹ��ˡ�\n");

    gold->add_amount(-how);
    addn("max_laodu", how, ob);
    addn("now_laodu", how, ob);
    ob->save();
    house  = query("house/" + query("type", ob), me);
    value  = house["value"] + how;
    house += ([ "value" : value, ]);
    me->save();
    message_vision("$N�����룬�е���ԥ�ش������ͳ�"HIY + chinese_number(how) +
                   "���ƽ�"NOR"����ϸ�������˴����ϡ�\n"
                   HIC"\n\t"+query("owner_name", ob)+"�Ĵ�����Ϊ������"
                       "�ƽ������ζ�����ˣ�\n\n" NOR, me);
    tell_object(me, HIW "Ŀǰ���ŵ�����ζ�Ϊ��"HIY
                    +chinese_number(query("max_laodu", ob) )
                    + HIW"���㣬��ǰ�ζ�Ϊ��"HIY
                    +chinese_number(query("now_laodu", ob) )
                    + HIW"���㡣\n" NOR);
    return 1;
}

//����������ż������ܲ���������Ա����������ı��Ϳ����Ž�������
public int push_house_door(string arg, object me, object ob)
{
    object obj;
    string path, room;

    if(arg != "men"
        && arg != "door"
        && arg != "��"
        && arg != "����")
            return notify_fail("��Ҫ��ʲô��\n");

    if(query("exits/" + query("set_exits",ob)), ob)
        return notify_fail("���Ѿ������˺����ˣ���ֱ�ӽ�ȥ�ɣ�\n");

    if(query("exits/" + query("forbid_exits",ob)), ob)
        return notify_fail("���ǿ��ŵģ���ֱ�ӽ�ȥ�ɣ�\n");

    path=query("path", ob)+"/";
    room=path+query("set_entry", ob);

    if( query("type", ob) == "bang" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob )
             || query("bang/name", me) == query("owner_name", ob) )
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N��$n����ʩ��һ�񣺡�����������"
                               "һ·�����ˣ�������ɣ���\n", obj, me);
            }
            message_vision("$N����һ�ƣ���ֱ���˽�ȥ��\n", me);
            tell_room(room, "�����ƿ������˽�����\n");
            me->move(room);
            return 1;
        }

        if(query_temp("invited_guest/" + query("owner",ob)),me)
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N���˿�$n����ͷ������ԭ���ǹ�͵��ţ�"
                               "������ɣ���\n", obj, me);
            }
            message_vision("$N���������ƿ������˽�ȥ��\n", me);
            me->move(room);
            return 1;
        }
    }
    else
        if( query("type", ob) == "user" || query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N��$n����ʩ��һ�񣺡�����������"
                               "һ·�����ˣ�������ɣ���\n", obj, me);
            }
            message_vision("$N����һ�ƣ���ֱ���˽�ȥ��\n", me);
            me->move(room);
            return 1;
        }

        if(query_temp("invited_guest/" + query("owner",ob)),me)
        {
            if(objectp(obj = present("hu yuan", environment(me)))
                 && query("owner", obj) == query("owner", ob )
                && obj->is_livings() && !obj->is_fighting())
            {
                message_vision("$N���˿�$n����ͷ������ԭ���ǹ�͵��ţ�"
                               "������ɣ���\n", obj, me);
            }
            message_vision("$N���������ƿ������˽�ȥ��\n", me);
            tell_room(room, "�����ƿ������˽�����\n");
            me->move(room);
            return 1;
        }
    }
    else
        return 0;
}

//��Ȩ���������߿ɴ򵹻�Ժ���ٹ��ƴ��Ŵ���
public int break_house_door(string arg, object me, object ob)
{
    int i;
    object obj, where;
    string path, room, *file;

    if(!arg || arg == "")
        return 0;

    if(arg != "men"
        && arg != "door"
        && arg != "��"
        && arg != "����")
            return 0;

    if(query("exits/" + query("set_exits",ob)),ob)
        return notify_fail("���Ѿ����俪�ˡ�\n");

    if( query("type", ob) == "bang" )
    {
        if( query("bang/name", me) == query("owner_name", ob) )
            return notify_fail("���ǲ��ǳԴ�ҩ�ˣ�Ҫ���ԼҰ���Ĵ��ţ�\n");
    }
    else
        if( query("type", ob) == "user" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
                return notify_fail("���ǲ��ǳԴ�ҩ�ˣ�Ҫ���ԼҵĴ��ţ�\n");
    }
    else
        if( query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
                return notify_fail("���ǲ��ǳԴ�ҩ�ˣ�Ҫ���ԼҵĴ��ţ�\n");
        else
            return notify_fail("��լ����Ҳ�������ƻ����˵���ʡʡ�����ɣ�\n");
    }

    path=query("path", ob)+"/";
    room=path+query("set_entry", ob);

    if(objectp(obj = present("hu yuan", environment(me)))
         && query("owner", obj) == query("owner", ob )
        && obj->is_livings())
    {
        message_vision("$N������$n�ȵ����������Ĵ�ͽ���ҵ���������Ұ��"
                       "����ҹ�Զ�㣡��\n", obj, me);
        return 1;
    }

    //��������賬��100���ɹ���
    if( query("max_neili", me)<100 )
        return notify_fail("�������̫�٣��޷������������š�\n");

    //��ǰ����ȫ�����ɳ��ֹ���
    if( query("neili", me)<query("max_neili", me) )
        return notify_fail("��Ŀǰ������������ӯ���޷������������š�\n");

    message_vision("$N�������������һ������������˫��һ��һ�£�"
                   "һ������������ȥ......\n", me);

    file = get_dir(path);
    for(i = 0; i < sizeof(file); i++)   //������լ�����з��䶼�ɵõ����ž�ʾ
    {
        where = get_object(path + file[i]);
        if(where == environment(me))    //�����������ģ����ų���������
            continue;
        tell_room(where, BEEP + HIW "\n���Ŵ�ͻȻ�������䡱��һ�����죬"
                         "�����������ڷ������ţ�\n\n" NOR);
    }

    //�����ߵ�ǰ�����������ŵ�ǰ�ζȵ�20�����ű�����
    if( query("neili", me)>query("now_laodu", ob)*20 )
    {
        for(i = 0; i < sizeof(file); i++)//������լ�����з��䶼�ɵõ����ƾ�ʾ
        {
            where = get_object(path + file[i]);
            if(where == environment(me))    //�����������ģ����ų���������
                continue;
            tell_room(where, BEEP + HIR "\n���Ŵ�ͻȻ�������䡱��һ�����죬"
                         "����ȥ�Ǵ����Ѿ����俪�ˣ�\n\n" NOR);
        }
        message_vision("ֻ�����䡱��һ���죬$N�Ѱ�"
                       +query("owner_name", ob)+"�Ĵ������ˣ�\n",me);
        addn("neili", -(query("now_laodu", ob)), me);
        set("exits/"+query("set_exits", ob), room, ob);
        set("now_laodu", 0, ob);
        return 1;
    }
    else    //���Ž��͹�����������1/20�ζȣ��д�����
    {
        message_vision("ֻ�����䣡����һ���죬���Ż��˼��Σ������˲��ٵĳ�����\n", me);
        addn("now_laodu", -(query("neili", me)/20), ob);
        set("neili", 0, me);
        return 1;
    }
    return 1;
}

//��լ�����߿��޸Ļ�Ժ��������ͷ�Ρ��ǳơ�����������
public int modify_huyuan(string arg, object me, object ob)
{
    string item, msg, gender;
    mapping dbase;
    int i = strlen(msg);

    if(!arg || sscanf(arg, "%s %s", item, msg) != 2)
        return notify_fail(HIW "\nָ���ʽ: modify <����> <����>\n"
                           "\n���������\n"
                           "\tname       ����\n"
                           "\tnickname   ���\n"
                           "\ttitle      ͷ��\n"
                           "\tgender     �Ա�\n"
                           "\tdesc       ����\n"
                           "\nmodify [nickname|title|desc] none ��ʾɾ����\n" NOR);

    if(!ob->is_livings())
        return notify_fail("��....����Ȱ�" + ob->name(1) + "Ū����˵��\n");

    if(ob->is_fighting())
        return notify_fail("��....����ȵ�" + ob->name(1) + "�������˵��\n");

    switch(item)
    {
        case "desc":
        if(CHINESE_D->check_length(filter_color(msg)) > 100)
            return notify_fail("���趨������̫���ˡ�\n");
        if(msg == "none")
        {
            delete("long", ob);
            ob->save();
            return notify_fail("ɾ����Ժ����...�ɹ���\n");
        }
        set("long", trans_color(msg)+"\n", ob);
        ob->save();
        return notify_fail("�趨��Ժ����...�ɹ���\n");

        case "nickname" :
        if(CHINESE_D->check_length(filter_color(msg)) > 20)
            return notify_fail("���趨�����̫���ˡ�\n");
        if(msg == "none")
        {
            delete("nickname", ob);
            ob->save();
            return notify_fail("ɾ����Ժ���...�ɹ���\n");
        }
        set("nickname", trans_color(msg), ob);
        ob->save();
        return notify_fail("�趨��Ժ���...�ɹ���\n");

        case "title" :
        if(CHINESE_D->check_length(filter_color(msg)) > 20)
            return notify_fail("���趨��ͷ��̫���ˡ�\n");
        if(msg == "none")
        {
            delete("title", ob);
            ob->save();
            return notify_fail("ɾ����Ժͷ��...�ɹ���\n");
        }
        set("title", trans_color(msg), ob);
        ob->save();
        return notify_fail("�趨��Ժͷ��...�ɹ���\n");

        case "name" :
        if(CHINESE_D->check_control(msg))
            return notify_fail("���ֲ����п��Ʒ���\n");
        if(CHINESE_D->check_space(msg))
            return notify_fail("���ֱ��費���ո�\n");
        if(CHINESE_D->check_return(msg))
            return notify_fail("���ֱ��費���س�����\n");
        if(!CHINESE_D->check_chinese(msg))
            return notify_fail("���ֱ���ʹ�����ģ�\n");
        if(CHINESE_D->check_length(msg) > 10)
            return notify_fail("���趨������̫���ˡ�\n");
        if(member_array(msg, banned_name) != -1)
            return notify_fail("�������ֲ�̫�ð�......\n");
        if(!"/adm/daemons/ban_named"->valid_name(msg))
            return notify_fail("�Բ����������ֻ���������˵����š�\n");
        dbase = ob->query_entire_dbase();
        dbase["name"] = msg;
        set("modify/name", msg, ob);
        ob->save();
        return notify_fail("�趨��Ժ����...�ɹ���\n");

        case "gender" :
        if(msg != "����" && msg != "Ů��")
            return notify_fail("�Ա����Ϊ���Ի�Ů������һ�֣�\n");
        gender=query("generation_skill/gender", ob);
        if( query("gender", ob) == msg )
            return notify_fail("��Ժ��ǰ���Ա��Ѿ���" + msg + "�ˡ�\n");
        if(gender == "male" && msg == "Ů��")
            return notify_fail("�趨��Ч����Ժ��ǰ��ʹ�õļ��ܽ������ԡ�\n");
        if(gender == "female" && msg == "����")
            return notify_fail("�趨��Ч����Ժ��ǰ��ʹ�õļ��ܽ���Ů�ԡ�\n");
        set("gender", msg, ob);
        ob->save();
        return notify_fail("�趨��Ժ�Ա�...�ɹ���\n");
    }
    return notify_fail("��Ҫ�趨ʲô��\n");
}

//��լ�����߿����ӡ�ɾ�����鿴�����ڻ�Ժ���Ĺ���б�
public int add_guest(string arg, object me, object ob)
{
    int i, how;
    string who, msg, *key;
    mapping vip;

    msg = HIW "\n���ӹ����setvip <ID> -add\n"
              "ɾ�������setvip <ID> -del\n"
              "����б�setvip  -list\n" NOR;

    if(!arg || arg == "")
        return notify_fail(msg);

    if(!ob->is_livings())
        return notify_fail("��....����Ȱ�" + ob->name(1) + "Ū����˵��\n");

    if(ob->is_fighting())
        return notify_fail("��....����ȵ�" + ob->name(1) + "�������˵��\n");

    vip=query("vip", ob);
    how=query("vip_limit", ob);
    if((int)how <= 0)
        how = VIP_ORIGIN;
    if(arg == "-list")
    {
        msg = ob->name(1) + "���������㣺";
        if(sizeof(vip) == 0)
        {
            msg += "Ŀǰû���趨�κι����\n";
            msg += sprintf(WHT "��ǰ�����趨" HIY "%s" NOR WHT "λ�����ʣ��"
                           HIW "%s" NOR WHT "����λ��\n" NOR,
                            chinese_number(how), chinese_number(how - sizeof(vip)));
            return notify_fail(msg);
        }
        msg += "\nĿǰ�ڹ����������������ң�\n";
        msg += HIG "------------------------------\n" NOR;
        key = sort_array(keys(vip), 1);
        for(i = 0; i < sizeof(key); i++)
        {
            msg += HIY + key[i] + "\n" NOR;
        }
        msg += HIG "------------------------------\n" NOR;
        msg += "���� " HIC + chinese_number(sizeof(vip)) + NOR " λ�����\n";
        msg += sprintf(WHT "��ǰ�����趨" HIY "%s" NOR WHT "λ�����ʣ��"
                       HIW "%s" NOR WHT "����λ��\n" NOR,
                        chinese_number(how), chinese_number(how - sizeof(vip)));
        return notify_fail(msg);
    }
    else
        if(sscanf(arg, "%s -add", who))
    {
        if( query("id", me) == who
             || query("couple/couple_id", me) == who )
        {
            msg = ob->name(1) + "Ц����ֱ�����ž��ܽ�ȥ�ģ����üӽ����������\n";
            return notify_fail(msg);
        }
        if( query("vip/"+who, ob) )
        {
            msg = ob->name(1) + "Ц������" + who + "���Ѿ��ڹ������֮���ˡ�\n";
            return notify_fail(msg);
        }
        if(sizeof(vip) >= how)
        {
            msg = ob->name(1) + "ҡͷ����Ŀǰ�Ѿ��������㹻��Ĺ�������ˡ�\n";
            return notify_fail(msg);
        }
        set("vip/"+who,query("id",  me), ob);
        ob->save();
        msg = ob->name(1) + "��ͷ������" + who + "���ѱ�����������֮�С�\n";
        return notify_fail(msg);
    }
    else
        if(sscanf(arg, "%s -del", who))
    {
        if( !query("vip/"+who, ob) )
        {
            msg = ob->name(1) + "ҡͷ������" + who + "��Ŀǰ�����ڹ�������ϡ�\n";
            return notify_fail(msg);
        }
        delete("vip/"+who, ob);
        ob->save();
        msg = ob->name(1) + "��ͷ������" + who + "���Ѿ��ӹ��������ɾ����\n";
        return notify_fail(msg);
    }
    else
        return notify_fail(msg);
}

//��լ�����߿ɻ�Ǯ���令Ժ���Ĺ���б�����
public int add_vip_limit(int value, object me, object ob)
{
    int i, how, new_value;
    object huyuan, *list;
    mapping house;

    huyuan=get_object(query_temp("house_addvips/huyuan", me));
    if(!huyuan)
        return notify_fail("��Ժ�����Ѱ����\n");

    if( query("bank/gold", me)<value )
        return notify_fail("��Ĵ�����\n");

    how=query("vip_limit", huyuan);//��ȡԭ�й������
    if((int)how <= 0)
        how = VIP_ORIGIN;

    how += 1;
    set("vip_limit", how, huyuan);//����һ���������
    huyuan->save();
    list = children(file_name(huyuan));
    for(i = 0; i < sizeof(list); i++)
    {
        if(environment(list[i]))
            destruct(environment(list[i]));
    }

    house = query("house/" + huyuan->query("type",huyuan),me);
    new_value = house["value"] + value;
    house += ([ "value" : new_value, ]);    //���ü�����լ��ֵ
    addn("bank/gold", -value, me);//�Ӵ���п۳�����
    me->save();
    delete_temp("house_addvips", me);
    tell_object(me, sprintf(HIC "\n%s�����ͷЦ��������޶�������Ϊ%sλ��"
                                "����%s���ƽ��Ѵ���Ĵ���ڿ۳���\n" NOR,
                                    ob->name(1), chinese_number(how),
                                    chinese_number(value)));
    return 1;
}

//����б��������ֵģ���Ժ��ѯ��ɻ���������ڵ���ʱȨ��
public int ask_guest(object me, object ob)
{
    if(!ob->is_livings())
        return 0;

    if(ob->is_fighting())
        return notify_fail("��....����ȵ�" + ob->name(1) + "�������˵��\n");

    if( query("type", ob) == "bang" )
    {
        if( query("bang/name", me) == query("owner_name", ob) )
        {
            message_vision("$N��$n����ʩ��һ�񣺡�����������"
                           "һ·�����ˣ�������ɣ���\n", ob, me);
            return 1;
        }
    }
    else
        if( query("type", ob) == "user" || query("type", ob) == "xian" )
    {
        if( query("id", me) == query("owner", ob )
             || query("couple/couple_id", me) == query("owner", ob) )
        {
            message_vision("$N��$n����ʩ��һ�񣺡�����������"
                           "һ·�����ˣ�������ɣ���\n", ob, me);
            return 1;
        }
    }

   if( query("vip/"+query("id", me)), ob)
    {
        set_temp("invited_guest/"+query("owner", ob), 1, me);
        message_vision("$N���˿�$n����ͷ������ԭ���ǹ�͵��ţ�"
                       "������ɣ���\n", ob, me);
        return 1;
    }
    else
    {
        message_vision("$N������$n���ۣ��ɻ��ҡ��ҡͷ��\n", ob, me);
        return 1;
    }
}

//��լ�����߼�����ż������������һ������ĳ��ǰ������
//�������߽�������Ž��ݵ���ʱȨ��
public int invite_guest(object me, string arg)
{
    int i;
    object ob, obj, *user;

    if(!arg || arg == "")
        return notify_fail("��������˭�����ͣ�\n");

    user = users();
    for(i = 0; i < sizeof(user); i++)
    {
        if( arg == user[i]->name(1) || arg == query("id", user[i]) )
            obj = user[i];
    }

    if( !obj || (wizardp(obj) && query("env/invisibility", obj)>1) )
        return notify_fail("��������������ں����ڡ�\n");

    if(obj->is_ghost())
        return notify_fail("������������ƺ��������䡣\n");

    if(!obj->is_livings())
        return notify_fail("�����������Ŀǰ�����޷�������Ϣ��\n");

    if( query("id", obj) == query("id", me) )
        return notify_fail("�Լ������Լ���û���ɣ�\n");

    if( query("id", obj) == query("couple/couple_id", me) )
        return notify_fail("�Լ�����ż����ֱ�ӽ������������롣\n");

    ob = environment(me);
    if( query("type", ob) == "bang"
         && query("bang/name", obj) == query("owner_name", ob) )
            return notify_fail("������˿���ֱ�ӽ�����פ�أ��������롣\n");

    set_temp("invited_guest/"+query("owner", ob), 1, obj);
    tell_object(me, HIC "���������" + obj->name() + "ǰ�����͡�\n" NOR);
    tell_object(obj, HIM "\n" + me->name(1) + "������ǰȥ���͡�\n" NOR);
    return 1;
}


//�����߿ɲ�ѯ��Ժ��ʹ�õļ��ܣ����ɻ�ȡ���пɹ�ѡ��ļ�����Ϣ
public int ask_huyuan_faction(object me, object ob)
{
    string name, code, topic;

    if(!ob->is_livings())
        return notify_fail("��....����Ȱ�" + ob->name(1) + "Ū����˵��\n");

    if(ob->is_fighting())
    {
        message_vision("$N��$nҡͷ������ʲô�µ��Ҵ������˵��\n", ob, me);
        return 1;
    }

    if( query("id", me) != query("owner", ob) && !wizardp(me) )
    {
        message_vision("$N��$nҡͷ������Щ������������ѯ�ʵġ�\n", ob, me);
        return 1;
    }

    name=query("generation_skill/name", ob);
    code=query("generation_skill/code", ob);
    if(!name)
    {
        FACTION_D->show_skill(me, 0);
        return 1;
    }

    topic=query_temp("last_ask/topic", me);
    if( query_temp("ask_all_faction", me) )
    {
        topic = "";
        FACTION_D->show_skill(me, 0);
    }
    else
        if(topic != name && topic != code)
    {
        message("vision", ob->name(1) + "��" + me->name() + "����С����"
                          "�ֹ��˼��䡣\n", environment(me), ({ me, ob }));
        tell_object(me, HIW + ob->name(1) + "�����ͷЦ����\n" NOR);
        FACTION_D->show_skill(me, topic);
    }

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "�ֹ��˼��䡣\n", environment(me), ({ me, ob }));
    tell_object(me, HIW + ob->name(1) + "ʩ��һ�������Ŀǰʹ�õļ����ǡ�"
                    HIY + name + HIW "����\n" NOR);
    FACTION_D->show_skill(me, name);

    if( query_temp("query_faction", me )
         && !query_temp("ask_all_faction", me) )
    {
        tell_object(me, HIC "\n" + ob->name(1) + "�����������Ҳ�ѯ��"
                        HIG "�书����" HIC "���ɻ�ȡ���п�ѡ��ļ���"
                            "��Ϣ��\n" NOR);
    }

    delete_temp("query_faction", me);
    delete_temp("ask_all_faction", me);
    return 1;
}

//�����������ϵĻƽ���������Ժ�ļ��ܵȼ�
public int shenji_huyuan(string arg, object me, object ob)
{
    object gold;
    mapping house;
    int how, value;

    if( query("id", me) != query("owner", ob) )
        return notify_fail("ʲô��\n");

    if(!arg || sscanf(arg, "%d gold", how) != 1)
       return notify_fail("��Ҫ���������ƽ�(" HIG "shengji *** gold"NOR
                           ")��������Ժ�ĵȼ���\n");

    if(!(gold = present("gold_money", me)))
        return notify_fail("�����Ϻ���û�д��ƽ�ɣ�\n");

    if((int)gold->query_amount() < how)
        return notify_fail("�����Ϻ���û�д���ô��Ļƽ�ɣ�\n");

    if(how < 50 || how % 50 != 0)
        return notify_fail("������Ժ�Ļƽ���Ŀ��������ʮ����������\n");

    if(!ob->is_livings())
        return notify_fail("��....����Ȱ�" + ob->name(1) + "Ū����˵��\n");

    if(ob->is_fighting())
        return notify_fail("��....����ȵ�" + ob->name(1) + "�������˵��\n");

    if( query("set_skill/level", ob) >= 900 )
    {
        ask_huyuan_level(me, ob);
        return 1;
    }

    if( (query("set_skill/level", ob)+(how/50))>900 )
    {
        message("vision", YEL + ob->name(1) + "ҡͷ�����㸶��Ǯ̫���ˣ��ҵ�"
                              "���ܵȼ���಻�ܳ����Űټ���\n", me,
                                            ({ environment(me), ob }));
        ask_huyuan_level(me, ob);
        return 1;
    }

    gold->add_amount(-how);
    addn("set_skill/level", how/50, ob);
    FACTION_D->gen_npc(ob,query("generation_skill/name", ob));
    ob->save();
    ob->restore();
    house=query("house/"+query("type", me), ob);
    value  = house["value"] + how;
    house += ([ "value" : value, ]);
    me->save();
    message_vision("$N�����룬�е���ԥ�ش������ͳ�"HIY + chinese_number(how) +
                   "���ƽ�"NOR"���ݸ���" + ob->name(1) + "��\n"
                   HIC "\n\t" + ob->name(1) + "��Ϊ�����"
                       "�ƽ����������ܵȼ�����ˣ�\n\n" NOR, me);
    ask_huyuan_level(me, ob);
    return 1;
}

//�����߿ɲ�ѯ��Ժ�ĵ�ǰ���ܵȼ�
public int ask_huyuan_level(object me, object ob)
{
    if(!ob->is_livings())
        return notify_fail("��....����Ȱ�" + ob->name(1) + "Ū����˵��\n");

    if(ob->is_fighting())
    {
        message_vision("$N��$nҡͷ������ʲô�µ��Ҵ������˵��\n", ob, me);
        return 1;
    }

    if( query("id", me) != query("owner", ob) && !wizardp(me) )
    {
        message_vision("$N��$nҡͷ������Щ������������ѯ�ʵġ�\n", ob, me);
        return 1;
    }

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "�ֹ��˼��䡣\n", environment(me), ({ me, ob }));

    tell_object(me, HIW + ob->name(1) + "���ĵĸ����㣺��Ŀǰ�ļ��ܵȼ�Ϊ"
                    HIY+chinese_number(query("set_skill/level", ob)));

    if( query("set_skill/level", ob) >= 900 )
    {
        tell_object(me, HIW "�����Ѵ�����޶ȡ�\n" NOR);
    }
    else
    {
        tell_object(me, HIW "��������������ء�\n" NOR);
        message("vision", HIC + ob->name(1) + "�����ֵ���ÿ��"
                          HIY "��ʮ���ƽ�" HIC "������������һ����"
                          "��߿ɵ�" HIR "�Ű�" HIC "����\n" NOR, me,
                                                ({ environment(me), ob }));
    }

    return 1;
}

//������ӵ��һ�θ��Ļ�Ժ��ʹ�õļ��ܵ�Ȩ��
public int set_huyuan_skill(string arg, object me, object ob)
{
    object obj;
    string who, skill;

    if(!arg || sscanf(arg, "%s use %s", who, skill) != 2)
        return notify_fail(HIW "ָ���ʽ��setskill <��ԺID> "
                               "use <��������>\n" NOR);

    obj = present(who, environment(me));
    if(!objectp(obj))
        return notify_fail(YEL "��Ҫ�趨˭�ļ��ܣ�\n" NOR);

    if( query("id", obj) != query("id", ob) )
        return notify_fail(YEL "��ֻ��Ϊ�Լ��Ļ�Ժ�趨���ܡ�\n" NOR);

    if( query("owner", obj) != query("id", me) )
        return notify_fail(YEL + obj->name(1) + "��������Ļ�Ժ��"
                                "����Ȩ�趨�似�ܡ�\n" NOR);

    if(!obj->is_livings())
        return notify_fail("��....����Ȱ�" + obj->name(1) + "Ū����˵��\n");

    if(obj->is_fighting())
        return notify_fail("��....����ȵ�" + obj->name(1) + "�������˵��\n");

    if( query("set_skill/owner", obj) == query("id", me) )
        return notify_fail(YEL + "���Ѿ�Ϊ" + obj->name(1) +
                                 "�趨�������ˣ��޷��ٴθ��ġ�\n" NOR);

    if( query("generation_skill/name", obj) == skill )
        return notify_fail(YEL + obj->name(1) + "��ǰʹ�õļ������ǡ�"
                               + skill + "���������ظ��趨��\n" NOR);

    FACTION_D->show_skill(me, skill);

    if( !query_temp("query_faction", me) )
        return 1;
    else
    {
        tell_object(me, HIC "\n��ȷ��Ҫ��"HIW + obj->name(1) +
                        HIC"�ļ��ܸ���Ϊ��"HIY + skill +
                        HIC"����(y/n)��\n" NOR);
        input_to("confirm_setskill", me, obj);
        return 1;
    }
}

//ȷ�ϸ��Ļ�Ժ�ļ���
public void confirm_setskill(string yn, object me, object ob)
{
   string arg=query_temp("query_faction", me);

    if(!arg)
    {
        tell_object(me, HIR "�������ݴ��󣬼������Ʋ�����\n" NOR);
        return;
    }

    if(yn == "" || (yn[0] != 'y' && yn[0] != 'Y'))
    {
        tell_object(me, YEL "��ı����⣬��������" + ob->name(1) +
                            "�ļ����趨Ϊ��" + arg + "���ˡ�\n" NOR);
        delete_temp("query_faction", me);
        return;
    }
    else
    {
        FACTION_D->gen_npc(ob, arg);
        set("set_skill/owner",query("id",  me), ob);
        ob->save();
        tell_object(me, HIG "\n�㽫"HIW + ob->name(1) + HIG"�ļ����趨Ϊ�ˡ�"
                        HIY + arg + HIG"��������ٸ��ġ�\n" NOR);
        delete_temp("query_faction", me);
        return;
    }
}

//�������һ�����룬���ڱ���ת�á�����İ�ȫ���ɹ��ⲿ�������
public string random_generation_password(int passlen)
{

    int i, dictlen;
    string passstr, dictionary;

    passstr = "";
    dictionary = "1234567890";
    dictionary += "abcdefghijklmnopqrstuvwxyz";
    dictionary += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    dictionary += "!@#$%^&*()_-+=\|/?,.:'";
    dictlen = strlen(dictionary);

    if(!passlen || passlen == 0)
        passlen = random(4) + 5;    // '5' is min password string length

    for(i = 0; i < passlen; i++)
    {
        passstr += sprintf("%c", dictionary[random(dictlen)]);
    }
    return passstr;
}
