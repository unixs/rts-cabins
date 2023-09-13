class Cabin < DefaultCabin
  def initialize()
    puts "Cabin is initialized."
  end

  def switched(loco)
    puts "switched => #{loco}"

    nil
  end

  def can_switch(loco, engine, id, set_state)
    true
  end

  def frame(engine, loco, state, time, air_t)
    nil
  end

  def change_loco(loco, prev, state)
    nil
  end

  def can_work_with(loco, type)
    false
  end

end
