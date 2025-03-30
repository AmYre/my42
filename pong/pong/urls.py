from django.urls import path, include
from . import views
from . import api

urlpatterns = [
    path('', views.home, name='home'),
    path('dashboard/', views.dashboard, name='dashboard'),
	path('api/auth/', api.auth, name='auth'),
	path('api/logout/', api.logout, name='logout'),
	path('api/dash/', api.dash, name='dash'),
	path('api/validate/', api.validate, name='validate'),
	path("__reload__/", include("django_browser_reload.urls")),
]