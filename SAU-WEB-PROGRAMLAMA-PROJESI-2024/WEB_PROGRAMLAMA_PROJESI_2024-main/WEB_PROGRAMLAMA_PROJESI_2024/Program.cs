using Microsoft.EntityFrameworkCore;
using WEB_PROGRAMLAMA_PROJESI_2024.Data;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

// Veritabaný baðlamý ekleniyor
builder.Services.AddDbContext<ApplicationDbContext>(options =>
{
    options.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection"));
});
/*
// CORS politikalarý ekleniyor
builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowAll", policy =>
    {
        policy.AllowAnyOrigin() // Tüm kaynaklara izin ver
              .AllowAnyMethod() // GET, POST, PUT, DELETE gibi tüm metotlara izin ver
              .AllowAnyHeader(); // Tüm baþlýklara izin ver
    });
});

bunu açarsan aþaðýdakini de aç
*/
// Oturum hizmetleri ekleniyor
builder.Services.AddSession(options =>
{
    options.IdleTimeout = TimeSpan.FromMinutes(30); // Oturum süresi 30 dakika
    options.Cookie.HttpOnly = true;                // Güvenlik için sadece HTTP ile eriþilebilir
    options.Cookie.IsEssential = true;             // Çerez, zorunlu olarak iþaretleniyor
    options.Cookie.Name = ".WEB_PROGRAMLAMA_PROJESI.Session"; // Çerez adý özelleþtiriliyor
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
}
else
{
    app.UseDeveloperExceptionPage(); // Geliþtirme ortamý için hata ayýklama sayfasý
}

app.UseStaticFiles();

app.UseRouting();

// CORS politikasý etkinleþtiriliyor
//app.UseCors("AllowAll");   // yukarýyý açarsan bunu da aç

// Oturumlar etkinleþtiriliyor
app.UseSession();

app.UseAuthorization();

// Varsayýlan rota yapýlandýrmasý
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Anasayfa}/{id?}");

app.Run();
