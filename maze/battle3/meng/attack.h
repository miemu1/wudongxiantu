// �����η���
int sqrt3(int x)
{
        float y = 1.0 / 3.0;
        x = to_int(pow(to_float(x), y));
        return x;
}

int get_exp_rate()
{
        int max_exp = 10000000, exp_rate;
        return 50000000;

        foreach (object user in users())
        {
                if (! environment(user)) continue;
                if (wizardp(user)) continue;

                if( query("combat_exp", user)>max_exp )
                        max_exp=query("combat_exp", user);
        }

        if (max_exp > 50000000) max_exp = 50000000;
        return max_exp;
}

int get_level(int exp)
{
        int level;

        exp /= 10000;
        level = sqrt3(exp);
        return level * 10;
}

void check_me(object me)
{
        object *ob, obb, env, room;
        string *dirs, dir, temp;
        mapping exits;
        int group, i;

        if (! objectp(me))
                me = this_object();
        if (! me) return;

        group=(query("eff_qi", me)-query("max_qi", me))/2000;
        if (group < 1) group = 1;
        set("qi",query("eff_qi",  me), me);
        set_temp("warequest/group", (group+1), me);
        env = environment(me);

        if (! living(me))
        {
                remove_call_out("check_me");
                call_out("check_me", 2, me);
                return;
        }

        ob = all_inventory(env);
        if( sizeof(ob)>0 && !query_temp("warequest/attack", me) )
        {
                for (i = 0; i < sizeof(ob); i++)
                {
                        obb = ob[i];
                        if (! obb->is_character() || ! living(obb))
                                continue;

                        if( query_temp("warequest/party", obb) != "meng" )
                        {
                                message_vision(HIC "$N��������������׼����һ��������г�����"
                                        + "�ķ���\n�����µ��ɹž����������⡪��ͻ������"
                                        + "$Nһ�����£�\n�����������ɹ������ʼ�˿��µĳ�棡��\n" NOR,
                                        me);

                                set_temp("warequest/attack", 1, me);
                                set_temp("warequest/attacking", 1, me);

                                remove_call_out("attack_over");
                                call_out("attack_over", 10, me);
                                dir = "south"; // ����������ֵ˿�����ö�û�У�������㸳ֵ��
                                               // ��ֵ��Ǻ���� attack_begin() ���� varargs ��
                                               // ����ȡ�� dir ��ȴ������������ include ԭ��
                                attack_begin(me, obb, env, env, dir);
                                break;
                        }
                }
                remove_call_out("check_me");
                call_out("check_me", 1, me);
                return;
        } else
        if( mapp(exits=query("exits", env) )
         && !query_temp("warequest/attack", me )
         && query("qi", me)>query_temp("warequest/group", me)*200
         && query("jing", me)>query_temp("warequest/group", me)*100 )
        {
                dirs = keys(exits);
                for (i = 0; i < sizeof(dirs); i++)
                if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                        dirs[i] = 0;
                dirs -= ({ 0 });
                if (mapp(exits)) dir = dirs[random(sizeof(dirs))];
                if (! room = find_object(exits[dir]))
                        room = load_object(exits[dir]);

                if (objectp(room))
                {
                        ob = all_inventory(room);
                        if (sizeof(ob) > 0)
                        {
                                for (i = 0; i < sizeof(ob); i++)
                                {
                                        obb = ob[i];
                                        if (! obb->is_character() || ! living(obb)) continue;
                                        if( query_temp("warequest/party", obb) != "meng" )
                                        {
                                                message_vision(HIC "$N�����������������׼����һ������������"
                                                        + "�����������⡪���������\n$Nһ�����£������뷢��\n" NOR, me);
                                                set_temp("warequest/attack", 1, me);
                                                set_temp("warequest/attacking", 1, me);

                                                remove_call_out("attack_over");
                                                call_out("attack_over", 10, me);
                                                attack_begin(me, obb, room, env, dir);
                                                break;
                                        }
                                }
                                remove_call_out("check_me");
                                call_out("check_me", 1, me);
                                return;
                        }
                }
        }

        if( !query_temp("warequest/attack", me) )
                delete_temp("warequest/attacking", me);

        remove_call_out("check_me");
        call_out("check_me", 1, me);
        return;
}

varargs void attack_begin(object me, object target, object room, object env, string dir)
{
        object weapon, bow, blade, weapon2, *ilist;
        int i;

        if (! objectp(me)) return;

        if (! objectp(target) || ! target->is_character())
                return;

        weapon=query_temp("weapon", me);
        if (weapon) weapon->unequip();

        blade = present("wan dao", me);
        ilist = all_inventory(me);
        for (i = 0; i < sizeof(ilist); i++)
        {
                if( query("is_bow", ilist[i]) )
                {
                        bow = ilist[i];
                        break;
                }
        }

        if (env == room) weapon2 = blade;
        else weapon2 = bow;
        if (objectp(weapon2))
                weapon2->wield();
        for(i=0;i<query_temp("warequest/group", me);i++ )
        {
                if( objectp(target) && objectp(weapon2) && query("equipped", weapon2) && query("is_bow", weapon2) && stringp(dir) )
                {
                        weapon2->do_shoot(query("id", target),me,weapon2,room,dir,1);
                        addn_temp("warequest/reward", 1, target);
                }
                else
                if (room == env && objectp(target))
                {
                        message_vision(HIC "$Nָ�ӵ��ɹ���������ڣ�"
                                       + "��������㳯$n�����˳������\n" NOR,
                                       me, target);
                        // COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

                        if( !objectp(target) || query("qi", target)<0 || 
                            environment(me) != environment(target))
                                break;

                        COMBAT_D->do_attack(me,target,query_temp("weapon", me));
                        addn_temp("warequest/reward", 2, target);
                } else break;
        }
        return;
}

void attack_over(object me)
{
        if (! objectp(me)) return;
        if (objectp(me))
        {
                message_vision(HIB"$N���о���һ�ӣ��ɹ��������һ��������"
                                + "��ʼ����׼��������һ�ֵĳ������\n"NOR,
                                me);
                delete_temp("warequest/attack", me);
        }
        return;
}

void init()
{
        add_action("do_kill", "team kill");
        add_action("do_kill", "touxi");
        add_action("do_kill", "kill");
        add_action("do_kill", "hit");
        add_action("do_kill", "fight");
        add_action("do_kill", "steal");
        add_action("do_kill", "beg");
        add_action("do_kill", "persuade");
        add_action("do_kill", "perform");
        add_action("do_kill", "yong");
        add_action("do_kill", "exert");
        add_action("do_kill", "yun");
        add_action("do_kill", "throw");
        add_action("do_kill", "conjure");
        add_action("do_kill", "recall");
}

int do_kill(string arg)
{
        string what, who;

        if (! arg) return 0;

        if (this_object()->id(arg))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        }
        else
        if (sscanf(arg, "%s from %s",what, who) == 2 && this_object()->id(who))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if (sscanf(arg, "%s at %s", what, who) == 2 && this_object()->id(who))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if (sscanf(arg, "%s on %s", what, who) == 2 && this_object()->id(who))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if (sscanf(arg, "%s %s", what, who) == 2 && this_object()->id(who))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if (arg == "roar" || arg == "hou")
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        }

        return 0;
}
