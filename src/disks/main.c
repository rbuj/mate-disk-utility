/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2008-2013 Red Hat, Inc.
 *
 * Licensed under GPL version 2 or later.
 *
 * Author: David Zeuthen <zeuthen@gmail.com>
 */

#include "config.h"
#include <glib/gi18n.h>
#include <libnotify/notify.h>

#include "gduapplication.h"

int
main (int argc, char *argv[])
{
  GApplication *app;
  gint status;

  /* Initialize gettext support */
  bindtextdomain (GETTEXT_PACKAGE, MATELOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  app = gdu_application_new ();
  notify_init ("org.mate.DiskUtility");
  status = g_application_run (G_APPLICATION (app), argc, argv);
  notify_uninit ();
  g_object_unref (app);

  return status;
}
