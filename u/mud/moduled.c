// This program is a part of NT MudLIB
// moduled.c
// �޸�֧��ͬʱ�������װ by lonely

/*
// ����װ����װ���ݸ�ʽ
<1>
<mod_name>$HIC$���$NOR$</mod_name>
<bas>5</bas>
<num>12</num>
<bas_prop>
add_busy:5
add_weak:5
reduce_busy:5
avoid_weak:5
</bas_prop>
<adv_prop>
avoid_locked:5
add_damage:20
add_skill:50
avoid_busy:5
counter_damage:20
add_locked:5
reduce_damage:5
</adv_prop>
</1>

// ������װ����װ��ʽ...
<M3000>
<mod_name>$CYNGRN$��֮����$NOR$</mod_name>
<mod_parts>
A3000:$CYNGRN$��֮����$NOR$
A3001:$CYNGRN$�����ۼ�$NOR$
A3002:$CYNGRN$��������$NOR$
A3003:$CYNGRN$��֮����$NOR$
A3004:$CYNGRN$����֮��$NOR$
A3005:$CYNGRN$�����ּ�$NOR$
A3006:$CYNGRN$����ս��$NOR$
</mod_parts>
<bas>3</bas>
<num>6</num>
<bas_prop>
avoid_locked:20
add_locked:20
add_busy:10
</bas_prop>
<adv_prop>
reduce_busy:20
avoid_busy:20
add_weak:10
avoid_weak:20
add_damage:20
reduce_damage:20
</adv_prop>
</M3000>

// ��������װ������ʽ...
<A3002>
<type>armor/surcoat</type>
<name>$CYNGRN$��������$NOR$</name>
<id>dragon surcoat</id>
<value>10000</value>
<mod_level>M3000</mod_level>
<mod_name>$CYNGRN$��֮����$NOR$</mod_name>
<require>
level:20
con:30
</require>
<quality_level>2</quality_level>
<armor_prop>
armor:10
</armor_prop>
<enchase>
apply_prop/armor1:10
apply_prop/str:2
apply_prop/dex:1
apply_prop/dodge:1
flute:2
used:2
</enchase>
<insert>
[1]
id:magic stone
name:��ʯ
apply_prop/armor1:10
apply_prop/str:2
[/1]
[2]
id:magic stone
name:��ʯ
apply_prop/dex:1
apply_prop/dodge:1
[/2]
</insert>
</A3002>
*/

#include <ansi.h>
inherit F_DBASE;

#define EQUIP_LIST      CONFIG_DIR "equiplist/"
#define NCH_CHANNEL(x) CHANNEL_D->channel_broadcast("nch", "��װ���飺"+(string)x)

class eqmodule
{
        string mod_level;       // ��װ��� ��Ϊ������ȡ����
        string mod_name;        // ��װ����
        mapping mod_parts;      // ��װ�������
        int bas;                // ��װ���������������
        int num;                // ��װ�������
        mapping bas_prop;       // ��װ��ϻ�������
        mapping adv_prop;       // ��װ��ϸ߼�����
        //mapping add_prop;       // ��װ��ϲ������ԣ���װ����Ӧ����bas_prop+adv_prop+add_prop
}

class eqmodule load_module(string modlevel);
nosave mixed all = ([]);
string module_stats(object obj, object owner);
int valid_module(class eqmodule mod_stats);
void equip_module(object ob, object owner);
void unequip_module(object ob, object owner);

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "��װ����");
        CHANNEL_D->do_channel(this_object(), "sys", "��װϵͳ�Ѿ�������");
}

// ������װ�����ͳ��в����ߴ�ӡ������Ϣ,Ӧ����look.c����
string module_stats(object ob, object owner)
{
        class eqmodule mod_stats;
        string modlevel, modname, *apply, *eq_files, *key;
        mapping modparts, data;
        mapping stats;
        int i, j, n, bas, num, len = 0;
        string msg, str, eq_str;

        // ��ʼ������
        msg = "";
        modlevel = query("mod_level", ob);
        modname = query("mod_name", ob);

        if( classp(query_temp("module/"+modlevel+"_"+modname, owner)) )
        {
                mod_stats = query_temp("module/"+modlevel+"_"+modname, owner); 
        }
        else
        {
                if( undefinedp(all[modlevel]) )
                        mod_stats = load_module(modlevel);
                else
                        mod_stats = copy(all[modlevel]);
        }

        // ���Ϸ���
        if( valid_module(mod_stats) )
        {
                num = mod_stats->num;   // ��װ��������
                // �����������װ������������װ����
                if( query_temp("module/"+modlevel+"_"+modname, owner) || !ob->is_item_make() )
                        modparts = mod_stats->mod_parts;

                // ����δ������װ����
                else
                        modparts = query_temp("module/modparts_" + modlevel+"_"+modname, owner);
                
                if( !mapp(modparts) ) modparts = ([]);
                apply = keys(modparts);
                
                msg = sprintf(HIW"  %s(%d/%d"NOR")\n",
                               modname,
                               query_temp("module/modamount_"+modlevel+"_"+modname, owner), num);
                msg+= sprintf(NOR "������������������������\n");

                data = query_temp("module/modparts_" + modlevel+"_"+modname, owner);
                if( !mapp(data) ) data = ([]);
                eq_files = keys(data);

                for( i=0;i<sizeof(apply);i++ )
                {
                        eq_str = "  ";

                        if( member_array(apply[i], eq_files) != -1 )
                                eq_str = WHT "��" NOR;

                        if( query("mod_mark", ob) == apply[i] )
                                if( query_temp("mod_equip", ob) )
                                        eq_str = HIR"��"NOR;
                                else
                                        eq_str = RED"��"NOR;

                        str = sprintf(NOR "��%s%-18s"NOR"��\n",eq_str, modparts[apply[i]]);
                        msg += str;
                }
                if( ob->is_item_make() && member_array(query("mod_mark", ob), apply) == -1 )
                {
                        eq_str = RED"��"NOR;
                        str = sprintf(NOR "��%s%-18s"NOR"��\n",eq_str, ob->name(1));
                        msg += str;
                }

                msg += sprintf(NOR "������������������������\n");
                bas = mod_stats->bas;
                if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) >= bas )
                        eq_str = HIR;
                else
                        eq_str = HIK;
                //msg += sprintf(HIG"  װ��Ч��"NOR")\n");
                msg += sprintf(NOR "%s������������������������"NOR"\n", eq_str);

                str = sprintf("%d��:", bas);
                msg += sprintf(NOR "%s��"NOR"%-20s%s��"NOR"\n", eq_str, str, eq_str);
                stats = copy(mod_stats->bas_prop);
                key = keys(stats);
                if( sizeof(key) > 0 )
                {
                        for( i=0;i<sizeof(key);i++ )
                        {
                                str = EQUIPMENT_D->chinese(key[i], stats[key[i]]);
                                str = HIG + str + NOR;
#ifndef LONELY_IMPROVED
                                len = color_len(str);
#endif
                                msg += sprintf(NOR "%s��"NOR"%-" + (20 + len) + "s%s��"NOR"\n",
                                                       eq_str, str, eq_str);
                        }
                }
                if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) == num )
                        eq_str = HIR;
                else
                        eq_str = HIK;
                str = sprintf("%d��:", num);
                msg += sprintf(NOR "%s��"NOR"%-20s%s��"NOR"\n", eq_str, str, eq_str);
                stats = copy(mod_stats->adv_prop);
                key = keys(stats);
                if( sizeof(key) > 0 )
                {
                        for( i=0;i<sizeof(key);i++ )
                        {
                                str = EQUIPMENT_D->chinese(key[i], stats[key[i]]);
                                str = HIG + str + NOR;
#ifndef LONELY_IMPROVED
                                len = color_len(str);
#endif
                                msg += sprintf(NOR "%s��"NOR"%-" + (20 + len) + "s%s��"NOR"\n",
                                                       eq_str, str, eq_str);
                        }
                }

                
                msg += sprintf(NOR "%s������������������������"NOR"\n", eq_str);
        }
        return msg;
}

// ���ݼ��һ����װ�Ƿ�Ϸ������Ƿ���ڣ������װ���ݻ��ǳ�ʼ�����ݣ����ǲ����ڡ�
int valid_module(class eqmodule mod_stats)
{
        if( mod_stats->mod_level == "" )
                return 0;

        if( mod_stats->mod_name == "" )
                return 0;
        /*
        if( !(mod_stats->mod_parts) )
                return 0;

        if( !(mod_stats->bas_prop) )
                return 0;

        if( !(mod_stats->adv_prop) )
                return 0;

        if( !(mod_stats->add_prop) )
                return 0;
        */
        return 1;
}

// ������Ų�����װ����
class eqmodule load_module(string modlevel)
{
        string filename, this_file, temp_str;
        object ob;
        class eqmodule item;
        string *field;
        string modname, names, bas_prop, adv_prop;
        int i, bas, num;
        mapping stats;
        string key;
        mixed value;

        if( modlevel[0] == 'M' )
        {
                if ( modlevel[1] == '0' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"basic.mod";
                else if ( modlevel[1] == '1' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"advance.mod";
                else if ( modlevel[1] == '2' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"expert.mod";
                else if ( modlevel[1] == '3' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"boss.mod";
        }
        else if( modlevel == "1" || modlevel == "2" || modlevel == "3" || modlevel == "4" )
        {
                // �������װ����װ��
                filename = EQUIP_LIST + "ultra.mod";
        }

        // ��ʼ��һ���յ���װ�ļ�
        item = new(class eqmodule);
        item->mod_level = "";
        item->mod_name = "";
        item->mod_parts = ([]);
        //item->add_prop = ([]); // װ���������ӵ���װ����

        // �ļ�Ϊ�ա����ؿ�ֵ��
        if( !stringp(filename) || file_size(filename) < 0 )
                return item;

        this_file = read_file(filename);

        // ������װ��Ų�����������ļ�������ƥ����װ����
        sscanf( this_file, "%*s<"+modlevel+">%s</"+modlevel+">%*s", temp_str);
        sscanf( temp_str, "%*s<mod_name>%s</mod_name>%*s", modname);
        sscanf( temp_str, "%*s<mod_parts>\n%s\n</mod_parts>%*s", names);
        sscanf( temp_str, "%*s<bas>%d</bas>%*s", bas);
        sscanf( temp_str, "%*s<num>%d</num>%*s", num);
        sscanf( temp_str, "%*s<bas_prop>\n%s\n</bas_prop>%*s", bas_prop);
        sscanf( temp_str, "%*s<adv_prop>\n%s\n</adv_prop>%*s", adv_prop);

        item->mod_level = modlevel;
        item->mod_name = trans_color(modname, 3); // ת����ɫ

        if( bas ) item->bas = bas;
        if( num ) item->num = num;

        // �������Ա��������Թؼ��ֺ���װ���ԡ�
        if (bas_prop != "")
        {
                stats = ([]);
                field = explode(bas_prop, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        if( sscanf( field[i], "%s:%d", key, value ) != 2 )
                            sscanf( field[i], "%s:%s", key, value );
                        // ���踴�ӵĽ���
                        stats[key] = value;
                }
                item->bas_prop = copy(stats);
        }

        if (adv_prop != "")
        {
                stats = ([]);
                field = explode(adv_prop, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        if( sscanf( field[i], "%s:%d", key, value ) != 2 )
                            sscanf( field[i], "%s:%s", key, value );
                        // ���踴�ӵĽ���
                        stats[key] = value;
                }
                item->adv_prop = copy(stats);
        }

        // �����ļ��������ļ����ƺ���װ�����������֡�
        if( sizeof(names) )
        {
                stats = ([]);
                field = explode(names, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        field[i] = trans_color(field[i], 3); // ת����ɫ
                        sscanf( field[i], "%s:%s", key, value );
                        stats[key] = value;
                }
                item->mod_parts = copy(stats);
        }
        
        if( !all ) all = ([]);
        all[modlevel] = copy(item);
        return item;
}

// װ����װ����
// ob��װ���� ownerװ����
void equip_module(object ob, object owner)
{
        class eqmodule mod_stats;
        class eqmodule tmp_stats;
        mapping data, stats, applied_prop;
        mapping modparts;
        string *apply;
        string modname;
        string modlevel, file, name;
        object *inv, *obs;
        int i, n;
        int bas, num;
        int max_qi, max_jing;
        
        if( ob->is_item_make() )
        {
                // ����װ����װ�������޷�������װ����
                if( ob->item_owner() != query("id", owner) )
                        return;
        }

        modlevel = query("mod_level", ob); // ��װ����š��ȼ�
        modname = query("mod_name", ob);   // modname ���ж��Ƿ�����װ
        
        inv = owner->query_equipment_objects(); // �Ż�Ч��
        if( ob->is_item_make() )        // �����װ����
        {
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) &&
                           $1->is_item_make() && $1->item_owner() == $(query("id", owner)) :));
        }
        else
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) && !$1->is_item_make() :));

        n = sizeof(obs); // װ������װ����
        
        // ������̻���ʱ����base_name��Ϊmark��������ò��������Ϊmark
        file = query("mod_mark", ob);
        name = query("name", ob);

        // �����װ���
        modparts=query_temp("module/modparts_"+modlevel+"_"+modname, owner);
        if( !mapp(modparts) || !sizeof(modparts) ) modparts = ([]);
        modparts[file] = name; 
        set_temp("module/modparts_"+modlevel+"_"+modname, modparts, owner);

        // �����װ����
        addn_temp("module/modamount_"+modlevel+"_"+modname, 1, owner);

        // װ������װ���ñ��
        set_temp("mod_equip", 1, ob);
        
        // ����2��������װ
        if( n < 2 ) return;
                
        // ��ȡ��װ����
        if( undefinedp(all[modlevel]) )
                mod_stats = load_module(modlevel);
        else
                mod_stats = copy(all[modlevel]);
                
        // ���Ϸ���
        //if( !valid_module(mod_stats) )
        //        return;

        bas = mod_stats->bas;
        num = mod_stats->num;

        if( n < bas ) return; // С�����ټ�����װ�������޷�������װ����
        else if( n == bas )
        {
                // ��������װ����ob�����ü�����װ����
                mod_stats->mod_name = modname; 
                if( ob->is_item_make() )        // ������װ�Ĳ�������
                        mod_stats->mod_parts = ([ file : name ]);

                set_temp("mod_active", 1, ob);  // lookʱ����ɫ�仯

                for( i=0; i<n; i++ ) {
                        if( ob->is_item_make() ) // ����������װ��������
                        {
                                data = copy(mod_stats->mod_parts);
                                data[query("mod_mark", obs[i])] = obs[i]->name(1);
                                mod_stats->mod_parts = copy(data);
                        }

                        set_temp("mod_active", 1, obs[i]);  // lookʱ����ɫ�仯�Լ������̻�����
                }
      
                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // ������ϱ����װ����
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);
        }
        else if( n == num )
        {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("��װ���Գ��ֻ��ң��������ύbug��admin��\n");

                // ��װȫ����
                mod_stats->mod_name = modname;  
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        data[file] = name;
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("mod_active", 1, ob);
                
                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // ������ϱ����װ����
                
                
                applied_prop = copy(mod_stats->bas_prop);
                stats = copy(mod_stats->adv_prop);
                apply = keys(stats);
                for( i = 0; i<sizeof(apply); i++ ) 
                {
                        if( undefinedp(applied_prop[apply[i]]) ) 
                                applied_prop[apply[i]] = stats[apply[i]]; 
                        else
                                applied_prop[apply[i]] += stats[apply[i]]; 
                }
                
                set_temp("fullsuit/"+modlevel+"_"+modname, applied_prop, owner);

                if( ob->is_item_make() ) // ������ȫ��װ��
                        set_temp("modequip_itemmake_level", to_int(modlevel), owner);     // ������ϱ��ȫ�׵�������װ�ȼ�
        }
        else
        {
                // �Ѿ�������װ���ԣ������µ���װ��������
                // ���ȼ���Ѿ��������װ�����Ƿ��������
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("��װ���Գ��ֻ��ң��������ύbug��admin��\n");

                mod_stats->mod_name = modname;  

                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        data[file] = name;
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("mod_active", 1, ob);

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // ������ϱ����װ����
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);
        }
        
        // ս������Ч
        if( query_temp("warquest", owner) ) return;
        
        owner->reset_buff_cache(); 

        max_qi = query("max_qi", owner);
        max_jing = query("max_jing", owner);
        CHAR_D->setup_char(owner);
        if( query("eff_qi", owner) >= max_qi )
                max_qi = query("max_qi", owner) - max_qi;
        else
                max_qi = 0;
        if( query("eff_jing", owner) >= max_jing )
                max_jing = query("max_jing", owner) - max_jing;
        else
                max_jing = 0;
        addn("eff_qi", max_qi, owner);
        addn("eff_jing", max_jing, owner);
                
        return;
}

// ж����װ����
// ob��װ���� ownerװ����
void unequip_module(object ob, object owner)
{
        class eqmodule mod_stats;
        class eqmodule tmp_stats;
        mapping data, stats, prop, applied_prop;
        mapping modparts;
        string *apply;
        string modname;
        string modlevel, file, name;
        object *inv, *obs;
        int i, j, n, flag = 0;
        int bas, num;

        if( ob->is_item_make() ) {
                if( ob->item_owner() != query("id", owner) )
                        return;
        }

        modlevel = query("mod_level", ob);
        modname = query("mod_name", ob);
        
        inv = owner->query_equipment_objects();
        if( ob->is_item_make() )        // �����װ����
        {
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) &&
                           $1->is_item_make() && $1->item_owner() == $(query("id", owner)) :));
        }
        else
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) && !$1->is_item_make() :));

        n = sizeof(obs);

        // �����װ����ob�Ƿ�����װ���һ��
        file = query("mod_mark", ob);
        name = query("name", ob);
        
        // �����װ�ļ�
        modparts=query_temp("module/modparts_"+modlevel+"_"+modname, owner);
        if( !mapp(modparts) || !sizeof(modparts) )
                modparts = ([]);
        
        map_delete(modparts, file);
        set_temp("module/modparts_"+modlevel+"_"+modname, modparts, owner);
        

        // �����װ����
        addn_temp("module/modamount_"+modlevel+"_"+modname, -1, owner);
        if( query_temp("module/modamount_"+modlevel+"_"+modname, owner)<=0 )
                delete_temp("module/modamount_"+modlevel+"_"+modname, owner);

        // ɾ��װ����װ�������
        delete_temp("mod_equip", ob);
        delete_temp("mod_active", ob); // lookʱ����ʾmod_prop��ɫ�仯

        /*
        if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) != n )
                error("��װװ���������ֻ��ң��������ύbug��admin��\n");
        */
        
        // ����2��������װ
        if( n < 1 ) return;
      

        // ��ȡ��װ����
        if( undefinedp(all[modlevel]) )
                mod_stats = load_module(modlevel);
        else
                mod_stats = copy(all[modlevel]);

        // ���Ϸ���
        //if( !valid_module(mod_stats) )
        //        return;
                
        bas = mod_stats->bas;
        num = mod_stats->num;

        // ���onwer����װ������װ����+1δ�ﵽ��װ�������ʱ��
        // ��Ϊû���ӹ���װ���ԣ����Բ���Ҫִ��ɾ��onwer��װ����
        if( n < bas-1 ) return;
        else if( n == bas-1 ) {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("��װ���Գ��ֻ��ң��������ύbug��admin��\n");

                // ����bas����ж����װ��������������װ�����в������Ժͻ�������
                for( i=0; i<sizeof(obs); i++ )
                {
                        if( obs[i] == ob ) continue;
                        delete_temp("mod_equip", obs[i]);   // ȡ��װ�����
                        delete_temp("mod_active", obs[i]);  // ȡ��������
                }

                delete_temp("module/"+modlevel+"_"+modname, owner);
                delete_temp("fullsuit/"+modlevel+"_"+modname, owner);

                return;
        }
        else if( n == num-1 ) {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("��װ���Գ��ֻ��ң��������ύbug��admin��\n");
                
                mod_stats->mod_name = modname;  
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        map_delete(data, file);
                        mod_stats->mod_parts = copy(data);
                }
                
                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);
                
                if( ob->is_item_make() )
                        delete_temp("modequip_itemmake_level", owner); // ɾ����װ�ȼ���suit special����

                return;
        }
        else
        {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("��װ���Գ��ֻ��ң��������ύbug��admin��\n");
                
                mod_stats->mod_name = modname;  // ������װ���Ʋ���һ��
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        map_delete(data, file);
                        mod_stats->mod_parts = copy(data);
                }
                
                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);

                return;
        }
}

// �������� /cmds/std/suit.c ʹ����װ�ؼ�
public int suit_special(object me, string arg)
{
        mapping buff, data;
        string msg;
        mapping map_status; 
        string *mname; 
        object *obs;
        int i, suitlvl, skill, temp;

        suitlvl = query_temp("modequip_itemmake_level", me);

        /*
        �����⸽����װ�ؼ� �ǳ�֮��(stars)��ʩչ(special stars <��Ŀ>)
        �����������ĳ��״̬ 50% �������� 10 ���ӡ�
        ���ӹ��������Ӷ����������мܡ������ڹ�������Ч���������˺�
        �������֡������С������˺����������С�˫���˺���
        �����˺����ֿ������������С����з������о�Ч������ȡЧ��
        */

        obs = me->query_equipment_objects(); 
        obs = filter_array(obs,
                        (: $1->is_item_make() /*&& $1->item_owner() == $(query("id", me))*/ :));
        
        if( sizeof(obs) < 9 )
                return notify_fail("��û��װ��ȫ�׵ľż�װ����\n");

        if( suitlvl < 4 )
                return notify_fail("��Ŀǰװ������װ�ȼ��������޷�ʹ����װ�ؼ���\n");
                                
        for( i=0; i<sizeof(obs); i++ )
        {
                if( query("qianghua/level", obs[i]) < 9 )
                        return notify_fail("����"+obs[i]->name(1)+NOR"���Ǿ���װ�����޷�ʹ����װ�ؼ���\n");
        }
        
        if( arg == "sun" ) // ��������
        {                   

                if( BUFF_D->check_buff(me, "powerofsun") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");
        
                if( query("neili", me) < 1000000 )
                        return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);
        
                msg = HIC "$N" HIC "һ��������ֻ��̫��֮��ԴԴ����������ȫ��װ����ɲ�Ǽ�������ʣ��������֣�\n" NOR;
                
                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status); 
                        temp = sizeof(map_status); 

                        for( i=0; i<temp; i++ ) 
                                data[mname[i]] = skill;
                }
                                
                data +=
                ([
                        "str"   : skill,
                        "attack": skill,
                        "ap_power": 200,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
//                        "type"  : "atkup",
//                        "type2" : "powerofsun",
                        "type" : "powerofsun",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ���̫��֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ���̫��֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }

        else if( arg == "moon" )  // �����˺�
        {
                if( BUFF_D->check_buff(me, "powerofmoon") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");

                if( query("neili", me) < 1000000 )
                        return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);
                
                msg = HIR "$N��ͷ���죬��Ȼһ����̾��ɲ�Ǽ�����֮��ԴԴ����������ȫ��װ����ȫ����ɫ�Ĺ�â������ɱ�����֣�\n" NOR;
                
                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status); 
                        temp = sizeof(map_status); 

                        for( i=0; i<temp; i++ ) 
                                data[mname[i]] = skill;
                }
                                
                data +=
                ([
                        "dex"   : skill,
                        "defense"   : skill,
                        "dp_power": 200,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
//                        "type"  : "damageup",
//                        "type2" : "powerofmoon",
                        "type" : "powerofmoon",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ�������֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ�������֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }
        
        else if( arg == "star" )
        {
                if( BUFF_D->check_buff(me, "powerofstar") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");

                if( query("neili", me) < 1000000 )
                        return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);
                
                msg = HIR "$N��Хһ������ʱ�ǳ�֮��ԴԴ����������ȫ��װ��������֮��������ɫѪâ�������ĵ��ߺ���\n" NOR;
                   
                data =
                ([
                        "leech_neili" : 30,
                        "leech_qi"    : 30,
                        "qi_abs_neili": 30,
                        "fatal_blow"  : 30,
                        "avoid_busy"  : 30,
                        "int"   : skill,
                        "con"   : skill,
                        "damage"   : skill,
                        "unarmed_damage"   : skill,
                        "da_power"   : 300,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
//                        "type"  : "powerup",
//                        "type2" : "powerofstar",
                        "type" : "powerofstar",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ����ǳ�֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ����ǳ�֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }
        
        else
                write("��װ�ؼ�ʹ�ø�ʽ��suit sun|moon|star\n");
     
        return 1;
}
