#include <gtk/gtk.h>

static void exp_one_print(GtkApplication* app, gpointer user_data){
    g_print("exp one success\n");
}

static void activate ( GtkApplication* app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "2exp");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget* grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget* print_button = gtk_button_new_with_label("print");
    g_signal_connect(print_button, "clicked", G_CALLBACK(exp_one_print), NULL);

    gtk_grid_attach(GTK_GRID(grid), print_button, 0, 0, 1, 1);

    GtkWidget* destroy_button = gtk_button_new_with_label("destroy");
    g_signal_connect_swapped(destroy_button, "clicked", 
        G_CALLBACK(gtk_widget_destroy), print_button);

    gtk_grid_attach(GTK_GRID(grid), destroy_button, 1, 0, 1, 1);

    GtkWidget* quit_button = gtk_button_new_with_label("quit");
    g_signal_connect_swapped(quit_button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_grid_attach(GTK_GRID(grid), quit_button, 0, 1, 3, 1);
    
    gtk_widget_show_all(window);
}

int main(int argc, char** argv){
    GtkApplication* app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
